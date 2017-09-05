/*
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
*/

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
    void helper(TreeNode* root, int startVal, int& retval) {
      if (!root) return;
      if (root->val - startVal + 1 > retval) retval = root->val - startVal + 1;
      if ((root->left) && root->left->val - root->val == 1) helper(root->left, startVal, retval);
      else if (root->left) helper(root->left, root->left->val, retval);
      if ((root->right) && root->right->val - root->val == 1) helper(root->right, startVal, retval);
      else if (root->right) helper(root->right, root->right->val, retval);
    }

    int longestConsecutive(TreeNode* root) {
      int retval = 1;
      if (!root) return 0;
      helper(root, root->val, retval);
      return retval;
    }
};
