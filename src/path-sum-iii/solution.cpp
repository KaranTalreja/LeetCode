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
    int helper( TreeNode* root, int sum, bool including) {
      if(root == NULL) return 0;
      int retval = 0;
      if (sum - root->val == 0) 
        retval += 1;
      retval += helper(root->left, sum - root->val, true);
      retval += helper(root->right, sum - root->val, true);
      if (including == false) {
        retval += helper(root->left, sum, false);
        retval += helper(root->right, sum, false);
      }
      return retval;
    }  

    int pathSum(TreeNode* root, int sum) {
      if(root == NULL) return 0;
      int retval = 0;
      if (root->val == sum) retval += 1;
      retval += helper(root->left, sum, false);
      retval += helper(root->right, sum, false);
      retval += helper(root->left, sum - root->val, true);
      retval += helper(root->right, sum - root->val, true);
      return retval;
    }
};
