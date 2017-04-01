/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
  public:
    void connect(TreeLinkNode *root) {
      if (root == NULL) return;
      if (root->left != NULL) {
        root->left->next = root->right;
        TreeLinkNode* left = root->left->right, *right = root->right->left;
        while (left != NULL && right != NULL) {
          left->next = right;
          left = left->right;
          right = right->left;
        }
      }
      connect(root->left);
      connect(root->right);
    }
};
