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
    void postOrder(TreeNode* root, int& sum) {
      if (NULL == root) return;
      postOrder(root->right, sum);
      root->val += sum;
      sum = root->val;
      postOrder(root->left, sum);
    }

    TreeNode* convertBST(TreeNode* root) {
      int sum = 0;
      postOrder(root, sum);
      return root;
    }
};
