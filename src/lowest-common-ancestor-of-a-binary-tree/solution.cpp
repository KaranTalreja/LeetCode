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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (root == NULL) return NULL;
      if (root == p || root == q) return root;
      TreeNode* leftRc = lowestCommonAncestor(root->left, p, q);
      TreeNode* rightRc = lowestCommonAncestor(root->right, p, q);
      if (NULL != leftRc && NULL != rightRc) return root;
      else if (NULL == leftRc) return rightRc;
      else return leftRc;
    }
};
