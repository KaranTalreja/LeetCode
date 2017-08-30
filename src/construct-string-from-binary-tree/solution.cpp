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
    void helper (TreeNode* t, string& retval) {
      retval += to_string(t->val);
      if (t->right && t->left) {
        retval += '(';
        helper(t->left, retval);
        retval += ")(";
        helper(t->right, retval);
        retval += ')';
      } else if (NULL == t->left && NULL != t->right) {
        retval += "()(";
        helper(t->right, retval);
        retval += ')';
      } else if (NULL == t->right && NULL != t->left) {
        retval += "(";
        helper(t->left, retval);
        retval += ')';
      }
    }

    string tree2str(TreeNode* t) {
      string retval;
      if (!t) return retval;
      helper(t, retval);
      return retval;
    }
};
