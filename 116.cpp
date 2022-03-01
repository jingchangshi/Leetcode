#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
  public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(): val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val): val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next): val(_val), left(_left), right(_right), next(_next) {}
};

void printBinaryTree(Node* root) {
  if (root==nullptr) {
    return;
  }
  queue<Node*> qe;
  qe.push(root);
  while (!qe.empty()) {
    Node* cur = qe.front();
    qe.pop();
    if (cur) {
      cout << cur->val << ",";
      if (cur->left || cur->right) {
        qe.push(cur->left);
        qe.push(cur->right);
      }
    } else {
      cout << "#" << ",";
    }
  }
  cout << endl;
}

void printConnectedBinaryTree(Node* root) {
  queue<Node*> qe;
  qe.push(root);
  while (!qe.empty()) {
    Node* cur = qe.front(); qe.pop();
    if (cur->left) {
      qe.push(cur->left);
    }
    while (cur) {
      cout << cur->val << ",";
      cur = cur->next;
    }
    cout << "#" << ",";
  }
  cout << endl;
}


class Solution {
  public:
    Node* connect(Node* root) {
      // BFS loop all levels.
      // At each level, use an additional queue to loop all elements in this level.
      // The standard NFS visits a single element each time.
      if (root==nullptr) {
        return root;
      }
      // not empty
      // Do not need to set up the root because the default value is nullptr
      // root->next = nullptr;
      queue<Node*> qe;
      qe.push(root);
      while (!qe.empty()) {
        // Each time, pop all elements in qe because they are in the same level.
        queue<Node*> qe_level;
        while (!qe.empty()) {
          Node* it = qe.front(); qe.pop();
          if (it->left) {
            // Not the end node
            qe_level.push(it->left);
            qe_level.push(it->right);
            // qe.push(it->left);
            // qe.push(it->right);
          }
        }
        while (!qe_level.empty()) {
          Node* cur = nullptr;
          Node* right = nullptr;
          cur = qe_level.front(); qe_level.pop();
          qe.push(cur);
          if (!qe_level.empty()) {
            right = qe_level.front(); // qe_level.pop();
            cur->next = right;
          } else {
            // qe_level is already empty. Thus cur is the rightmost node.
            cur->next = nullptr;
          }
        }
      }
      return root;
    }
};

int main(void) {
  Solution sol;
  Node node_empty;
  vector<Node> node_vec(7);
  vector<int> node_val_vec = {1,2,3,4,5,6,7};
  for (int i=0; i<7; i++) {
    node_vec[i].val = node_val_vec[i];
  }
  node_vec[0].left = &node_vec[1];
  node_vec[0].right = &node_vec[2];
  node_vec[1].left = &node_vec[3];
  node_vec[1].right = &node_vec[4];
  node_vec[2].left = &node_vec[5];
  node_vec[2].right = &node_vec[6];
  // print
  printBinaryTree(&node_vec[0]);
  //
  Node* connected = sol.connect(&node_vec[0]);
  // print
  printConnectedBinaryTree(connected);
  return 0;
}
