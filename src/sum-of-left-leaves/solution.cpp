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
    void helper(TreeNode* root, int &retval, bool left) {
      if (root == NULL) return;
      helper(root->left, retval, true);
      helper(root->right, retval, false);
      if (root->left == NULL && root->right == NULL && left == true) retval += root->val; 
    }
    int sumOfLeftLeaves(TreeNode* root) {
      int retval = 0;
      helper(root, retval, false);
      return retval;
    }
};
