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
      if (root==NULL) return;
      if (retval.size() <= depth) {
        vector<int> a;
        retval.push_back(a);
      }
      if (depth % 2) retval[depth].insert(retval[depth].begin(), root->val);
      else retval[depth].push_back(root->val);
      helper(root->left, retval, depth+1);
      helper(root->right, retval, depth+1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> retval;
      helper(root, retval, 0);
      return retval;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**class Solution {
  public:

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> retval;
      if (NULL == root) return retval;
      list<TreeNode*> level;
      level.push_back(root);
      int depth = 0;
      while (!level.empty()) {
        vector<int> a;
        retval.push_back(a);
        int size = level.size();
        for (int i = 0; i < size; i++) {
          TreeNode* currNode = level.front();
          level.pop_front();
          if (currNode->left) level.push_back(currNode->left);
          if (currNode->right) level.push_back(currNode->right);
          if (!(depth%2)) retval[depth].push_back(currNode->val);
          else retval[depth].insert(retval[depth].begin(), currNode->val);
        }
        depth++;
      }
      return retval;
    }
};*/
