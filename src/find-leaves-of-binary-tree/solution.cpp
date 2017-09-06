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
    void helper(TreeNode*& root, vector<int> &currPath, TreeNode* parent, bool left) {
      if (!root) return;
      if (!root->left && !root->right) { 
        currPath.push_back(root->val);
        if (parent && left) parent->left = NULL;
        else if (parent) parent->right = NULL;
        else root = NULL;
        return;
      }
      helper(root->left, currPath, root, true);
      helper(root->right, currPath, root, false);
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
      vector<vector<int>> retval;
      if(!root) return retval;
      while(root) {
        vector<int> currPath;
        helper(root, currPath, NULL, true);
        retval.push_back(currPath);
      }
      return retval;
    }
};
