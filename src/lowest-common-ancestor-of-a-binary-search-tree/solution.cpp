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
      int pVal = p->val > q->val ? p->val : q->val;
      int qVal = p->val > q->val ? q->val : p->val;
      int rVal = root->val;
      if (rVal == q->val) return q;
      if (rVal == p->val) return p;
      if (rVal > pVal) return lowestCommonAncestor(root->left, p, q);
      else if (rVal < qVal) return lowestCommonAncestor(root->right, p, q);
      else if (rVal < pVal && rVal > qVal) return root; 
    }
};
