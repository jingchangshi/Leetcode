#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
};

class Solution {
  public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      // record the n+1 from the end
      ListNode *prev_n_p1 = head, *prev_n_n1 = head, *cur = head;
      int cnt=1;
      while (cur->next != nullptr) {
        if (cnt>n) {
          prev_n_p1 = prev_n_p1->next;
        }
        if (cnt>=n-1) {
          prev_n_n1 = prev_n_n1->next;
        }
        cur = cur->next;
        cnt++;
      }
      if (cnt==1) {
        // n must be 1
        return nullptr;
      } else if (cnt==2) {
        if (n==1) {
          head->next = nullptr;
          return head;
        } else {
          // n==2
          return head->next;
        }
      } else {
        // cnt >= 3
        if (n==cnt) {
          return head->next;
        } else if (n==1) {
          prev_n_p1->next = nullptr;
          return head;
        } else {
          // cnt>n
          prev_n_p1->next = prev_n_n1;
          return head;
        }
      }
    }
};

int main (void) {
  Solution sol;
  int n = 1;
  vector<ListNode> list_nodes(n);
  list_nodes[n-1].val = n;
  list_nodes[n-1].next = nullptr;
  for (int i=n-2; i>=0; i--) {
    list_nodes[i].val = i+1;
    list_nodes[i].next = &list_nodes[i+1];
  }
  int nth = 1;
  ListNode* cur = sol.removeNthFromEnd(&list_nodes[0], nth);
  if (cur != nullptr) {
    cout << cur->val;
    while (cur->next != nullptr) {
      cur = cur->next;
      cout << "," << cur->val;
    }
    cout << endl;
  }
  return 0;
}
