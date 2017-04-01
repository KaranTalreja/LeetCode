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
    void helper(TreeNode* root, int startDepth, int& maxDepth, vector<int>& retval) {
      if (root == NULL) return;
      if (startDepth >= maxDepth) {
        retval.push_back(root->val);
        maxDepth++;
      }
      helper(root->right, startDepth+1, maxDepth, retval);
      helper(root->left, startDepth+1, maxDepth, retval);
    }

    vector<int> rightSideView(TreeNode* root) {
      vector<int> retval;
      int maxDepth = 0;
      helper(root, 0, maxDepth, retval);
      return retval;
    }
};
