/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000
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
    void longestUnivalPathOfValue(TreeNode* root, int value, int& retval) {
      if (!root) return;
      if (root->val == value) 
      {
        retval++;
        int left = 0, right =0;
        longestUnivalPathOfValue(root->left, value, left);
        longestUnivalPathOfValue(root->right, value, right);
        retval += max(left,right);
      } else 
        return;
    }

    int longestUnivaluePath(TreeNode* root) {
      if (!root) return 0;
      int left = longestUnivaluePath(root->left);
      int right = longestUnivaluePath(root->right);
      int includingLeft = 0;
      int includingRight = 0;
      longestUnivalPathOfValue(root->left, root->val, includingLeft);
      longestUnivalPathOfValue(root->right, root->val, includingRight);
      return max(max(left, right), includingLeft+includingRight);
    }
};

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
    int helper(TreeNode* root, int val) {
      if (!root || root->val != val) return 0;
      return max(helper(root->left, val), helper(root->right, val)) + 1;
    }

    int longestUnivaluePath(TreeNode* root) {
      if (!root) return 0;
      int rc1 = longestUnivaluePath(root->left);
      int rc2 = longestUnivaluePath(root->right);
      rc1 = rc2 > rc1 ? rc2 : rc1;
      rc2 = helper(root->left, root->val) + helper(root->right, root->val);
      rc1 = rc2 > rc1 ? rc2 : rc1;
      return rc1;
    }
};
