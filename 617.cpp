#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
  public:
    // Binary tree is a good example of local structure representing the global structure.
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
      if (root1==nullptr) {
        return root2;
      }
      if (root2==nullptr) {
        return root1;
      }
      TreeNode* root = new TreeNode(root1->val + root2->val);
      root->left = mergeTrees(root1->left, root2->left);
      root->right = mergeTrees(root1->right, root2->right);
      return root;
    }

    // Print must be breadth first search.
    // Otherwise it prints an array with the ordering different from the input.
    void printTrees(TreeNode* root) {
      queue<TreeNode*> qe;
      qe.push(root);
      while (!qe.empty()) {
        TreeNode* cur = qe.front();
        qe.pop();
        if (cur) {
          cout << cur->val << ",";
          // no child node exists in the end node
          if (cur->left || cur->right) {
            qe.push(cur->left);
            qe.push(cur->right);
          }
        } else {
          cout << "null" << ",";
        }
      }
      cout << endl;
    }
};

int main(void) {
  Solution sol;
  TreeNode tn;
  vector<int> root1 = {1,3,2,5};
  vector<TreeNode> t1(4);
  // t1.push_back(tn);
  // t1.push_back(tn);
  // t1.push_back(tn);
  t1[0].left = &t1[1];
  t1[0].right = &t1[2];
  t1[0].val = root1[0];
  t1[1].val = root1[1];
  t1[2].val = root1[2];
  // t1.push_back(tn);
  t1[1].left = &t1[3];
  t1[3].val = root1[3];
  vector<int> root2 = {2,1,3,0,4,0,7};
  vector<TreeNode> t2(7);
  // WARNING: If the following method of setting up the vector of TreeNode,
  //          the incremental way changes the memory layout of the vector.
  //          Thus at the end t2[1] is not t2[0].left.
  // t2.push_back(tn);
  // t2.push_back(tn);
  // t2.push_back(tn);
  t2[0].left = &t2[1];
  t2[0].right = &t2[2];
  t2[0].val = root2[0];
  t2[1].val = root2[1];
  t2[2].val = root2[2];
  // t2.push_back(tn);
  // t2.push_back(tn);
  t2[1].right = &t2[4];
  t2[4].val = root2[4];
  // t2.push_back(tn);
  // t2.push_back(tn);
  t2[2].right = &t2[6];
  t2[6].val = root2[6];
  // print
  sol.printTrees(&t1[0]);
  sol.printTrees(&t2[0]);
  //
  TreeNode* merged = sol.mergeTrees(&t1[0], &t2[0]);
  sol.printTrees(merged);
  return 0;
}
