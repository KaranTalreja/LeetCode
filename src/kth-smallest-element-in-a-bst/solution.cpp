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
    int count (TreeNode* root) {
      if (root == NULL) return 0;
      return count(root->left) + count(root->right) + 1; 
    }

    int kthSmallest(TreeNode* root, int k) {
      int leftCount = count(root->left);
      if (leftCount == k-1) return root->val;
      if (k > leftCount) return kthSmallest(root->right, k - (leftCount + 1));
      return kthSmallest(root->left, k);
    }
};
