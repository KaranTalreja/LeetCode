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
    TreeNode* helper(TreeNode* root, double& target, double& lower, double& upper) {
      if (!root) return root;
      if (target >= root->val) return helper(root->right, target, (lower = root->val), upper);
      else return helper(root->left, target, lower, (upper = root->val));
    }

    int closestValue(TreeNode* root, double target) {
      double lower = INT_MAX, upper = INT_MIN;
      TreeNode* rc = helper(root, target, lower, upper);
      int retval = 0;
      if (fabs(target - upper) < fabs(target - lower)) retval = upper;
      else retval = lower;
      return retval;
    }
};
