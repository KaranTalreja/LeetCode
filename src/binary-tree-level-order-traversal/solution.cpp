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
    void helper(TreeNode* root, vector<vector<int>>& retval, int depth) {
      if (root == NULL) return;
      if (retval.size() <= depth) {
        vector<int> a;
        retval.push_back(a);
      }
      retval[depth].push_back(root->val);
      helper(root->left,retval,depth+1);
      helper(root->right, retval, depth+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> retval;
      helper(root, retval, 0);
      return retval;
    }
};
