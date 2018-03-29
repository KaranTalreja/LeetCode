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
    TreeNode* helper (vector<int>& preorder, vector<int>& inorder, int& sp, int ep, int si, int ei) {
      if (sp > ep || si > ei) return NULL;
      TreeNode* root = new TreeNode(preorder[sp]);
      int i = si;
      for (i = si; i < ei; i++) {
        if (inorder[i] == preorder[sp]) break;
      }
      sp++;
      root->left = helper(preorder, inorder, sp, ep, si, i-1);
      root->right = helper(preorder, inorder, sp, ep, i+1, ei);
      return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int pSize = preorder.size();
      int iSize = inorder.size();
      int iStart = 0;
      int pStart = 0;
      return helper(preorder, inorder, pStart, pSize-1, iStart, iSize-1);
    }
};
