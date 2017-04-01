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
    void helper(TreeNode* root, vector<vector<int>>& queue, int depth) {
      if (NULL == root) return;
      if (depth + 1 > queue.size()) {
        vector<int> a;
        queue.insert(queue.begin(),a);
      }
      queue[queue.size()-1-depth].push_back(root->val);
      helper(root->left, queue, depth+1);
      helper(root->right, queue, depth+1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>> queue;
      helper(root, queue, 0);
      return queue;
    }
};
