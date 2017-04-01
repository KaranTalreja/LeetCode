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
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> retval;
      if (root == NULL) return retval;
      list<TreeNode*> left, centre;
      left.push_back(root);
      TreeNode* currNode = NULL;
      while (!centre.empty() || !left.empty()) {
        if (!left.empty()) {
          currNode = left.back();
          left.pop_back();
          centre.push_back(currNode);
          if (currNode->left) left.push_back(currNode->left);
        } else {
          currNode = centre.back();
          retval.push_back(currNode->val);
          centre.pop_back();
          if (currNode->right) left.push_back(currNode->right);
        }
      }
      return retval;
    }
};
