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
    void helper(TreeNode* root, int prefix, int& total_sum) {
      if (root == NULL) return;
      if (root->left == NULL && root->right == NULL) total_sum += prefix*10 + root->val;
      helper(root->left, prefix*10 + root->val, total_sum);
      helper(root->right, prefix*10 + root->val, total_sum);
    }

    int sumNumbers(TreeNode* root) {
      if (NULL == root) return 0;
      int total_sum = 0;
      helper(root, 0, total_sum);
      return total_sum;
    }
};
