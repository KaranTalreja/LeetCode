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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
      TreeNode* retval = NULL;
      if (!p) return retval;
      while (root != NULL) {
        if (p->val > root->val) root = root->right;
        else if (p->val < root->val) {
          retval = root;
          root = root->left;
        } else {
          root = root->right;
          while (root) {
            retval = root;
            root = root->left;
          }
        }
      }
      return retval;
    }
};
