/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    int helper(TreeNode* root, int depth) {
      if (root==NULL) return INT_MIN;
      int left = helper(root->left, depth+1);
      int right = helper(root->right, depth+1);
      if (root->left == NULL && root->right == NULL) return depth;
      return max(left,right);
    }

    int maxDepth(TreeNode* root) {
      int retval = helper(root, 1);
      if (retval == INT_MIN) return 0;
      return retval;
    }
};
