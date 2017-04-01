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
    int helper(TreeNode* root, int depth, bool& retval) {
      if (root==NULL) {
        retval = true;
        return depth-1;
      }
      int left = helper(root->left, depth+1, retval);
      if (retval == false) return left;
      int right = helper(root->right, depth+1, retval);
      if (retval == false) return right;
      if (root->left == NULL && root->right == NULL) {
        retval = true;
        return depth;
      }
      retval = (abs(left - right) > 1) ? false : true;
      return max(left,right);
    }

    bool isBalanced(TreeNode* root) {
      bool retval = false;
      helper(root, 0, retval);
      return retval;
    }
};
