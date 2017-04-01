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
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> retval;
      if (root == NULL) return retval;
      list<TreeNode*> stack;
      TreeNode* currNode = NULL;
      stack.push_back(root);
      while(!stack.empty()) {
        currNode = stack.back();
        stack.pop_back();
        retval.push_back(currNode->val);
        if (NULL != currNode->right)    stack.push_back(currNode->right);
        if (NULL != currNode->left) stack.push_back(currNode->left);
      }
      return retval;
    }
};
