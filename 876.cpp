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
  ListNode* middleNode(ListNode* head) {
    vector<ListNode*> ans = {head};
    while (ans.back()->next != nullptr) {
      ans.push_back(ans.back()->next);
    }
    return ans[ans.size()/2];
  }
};

int main (void) {
  Solution sol;
  int n = 5;
  vector<ListNode> list_nodes(n);
  list_nodes[n-1].val = n;
  for (int i=n-2; i>=0; i--) {
    list_nodes[i].val = i+1;
    list_nodes[i].next = &list_nodes[i+1];
  }
  ListNode* mid_ptr = sol.middleNode(&list_nodes[0]);
  cout << mid_ptr->val;
  while (mid_ptr->next != nullptr) {
    mid_ptr = mid_ptr->next;
    cout << "," << mid_ptr->val;
  }
  cout << endl;
}
