#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void dfsPreorder(TreeNode *root, vector<int> &vec) {
      if (root == nullptr) {
        return;
      }
      vec.push_back(root->val);
      dfsPreorder(root->left, vec);
      dfsPreorder(root->right, vec);
    }

    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> vec;
      dfsPreorder(root, vec);
      return vec;
    }

    TreeNode* buildTreeFromArray(vector<int>& inorder, vector<int>& postorder,
              int &root_idx, const int in_beg, const int in_end) {
        if (in_end - in_beg == 0) {
          return nullptr;
        }
        TreeNode *root = new TreeNode();
        int root_val = postorder[root_idx];
        root->val = root_val;
        root_idx--;
        if (in_end - in_beg == 1) {
          // Only 1 element exist. It is the root of this level.
          return root;
        }
        auto root_it = find(&inorder[in_beg], &inorder[in_end], root_val);
        // int left_end = root_it - &inorder[in_beg];
        int left_end = root_it - &inorder[0];
        int right_beg = left_end + 1;
        root->right = buildTreeFromArray(inorder, postorder, root_idx, right_beg, in_end);
        root->left = buildTreeFromArray(inorder, postorder, root_idx, in_beg, left_end);
        return root;
    }

    // The post order array lists the root node at each level.
    // The we can use the root node to split the in order array
    // to obtain the left and right child of the root node.
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      int n = postorder.size();
      int root_idx = n - 1;
      TreeNode *root = buildTreeFromArray(inorder, postorder, root_idx, 0, n);
      return root;
    }

};

int main(int argc, char **argv) {
  // vector<int> inorder = {9,3,15,20,7};
  // vector<int> postorder = {9,15,7,20,3};
  vector<int> inorder = {2,1};
  vector<int> postorder = {2,1};

  Solution sol;
  TreeNode* root = sol.buildTree(inorder, postorder);
  vector<int> res = sol.preorderTraversal(root);
  int n = res.size();
  for (int i = 0; i < n-1; i++) {
    printf("%d, ", res[i]);
  }
  printf("%d\n", res[n-1]);
  return 0;
}