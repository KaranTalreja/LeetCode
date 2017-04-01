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
    void helper(TreeNode* root, int sum, vector<vector<int>>& retval, vector<int>& prefix) {
      if (root == NULL) return;
      prefix.push_back(root->val);
      if (root->left == NULL && root->right == NULL && sum == root->val) {
        retval.push_back(prefix);
      }
      helper(root->left, sum - root->val, retval, prefix);
      helper(root->right, sum - root->val, retval, prefix);
      prefix.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      vector<vector<int>> retval;
      vector<int> prefix;
      helper(root, sum, retval, prefix);
      return retval;
    }
};
