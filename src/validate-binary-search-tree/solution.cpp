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
    bool inRange(TreeNode* root, long max, long min) {
      if(root == NULL) return true;
      if (root->val <= min || root->val >= max) return false;
      bool rc = inRange(root->left, root->val, min);
      if (rc == false) return false;
      return inRange(root->right, max, root->val);
    }

    bool isValidBST(TreeNode* root) {
      if (root == NULL) return true;
      bool rc = inRange(root->left, root->val, (long)INT_MIN-1);
      if (rc == false) return false;
      return inRange(root->right, (long)INT_MAX+1, root->val);
    }
};
