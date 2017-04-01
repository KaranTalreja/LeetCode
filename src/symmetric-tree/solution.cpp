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
    void invert (TreeNode* root) {
      if (root == NULL) return;
      TreeNode* temp = root->right;
      root->right = root->left;
      root->left = temp;
      invert(root->left);
      invert(root->right);
    }

    bool isSame(TreeNode* rootLeft, TreeNode* rootRight) {
      if (rootLeft == NULL && rootRight == NULL) return true;
      else if (rootLeft == NULL || rootRight == NULL) return false;
      if (rootLeft->val != rootRight->val) return false;
      bool rc = isSame(rootLeft->left, rootRight->left);
      if (rc == false) return false;
      return isSame(rootLeft->right, rootRight->right);
    }

    bool isSymmetric(TreeNode* root) {
      if (root == NULL) return true;
      invert(root->right);
      return isSame(root->left, root->right);
    }
};
