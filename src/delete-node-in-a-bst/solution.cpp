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
    TreeNode* helper(TreeNode* root, int key) {
      if (root == NULL) return root;
      if (root->val == key) {
        if (root->left == NULL && root->right == NULL) return NULL;
        if (root->left != NULL && root->right != NULL ) {
          TreeNode* pred = root->right;
          while (pred->left) {
            pred = pred->left;
          }
          root->val = pred->val;
          root->right = helper(root->right, pred->val);
          return root;
        } else {
          return (root->left) ? root->left : root->right;
        }
      } else {
        if (key < root->val) root->left = helper(root->left, key);
        else root->right = helper(root->right, key);
      }
      return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
      root = helper(root, key);
      return root;
    }
};
