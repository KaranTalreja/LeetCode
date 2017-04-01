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
    void helper(TreeNode* root, vector<int>& retval, int depth) {
      if (root==NULL) return;
      if (retval.size() <= depth) {
        retval.push_back(INT_MIN);
      }
      retval[depth] = retval[depth] > root->val ? retval[depth] : root->val;
      helper(root->left, retval, depth+1);
      helper(root->right, retval, depth+1);
    }

    vector<int> largestValues(TreeNode* root) {
      vector<int> retval;
      helper(root, retval, 0);
      return retval;
    }
};
