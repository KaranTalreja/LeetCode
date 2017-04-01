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
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> retval;
      if (root == NULL) return retval;
      list<TreeNode*> stack;
      stack.push_back(root);
      TreeNode* currNode = NULL;
      while (!stack.empty()) {
        currNode = stack.back();
        stack.pop_back();
        retval.insert(retval.begin(),currNode->val);
        if (currNode->left) stack.push_back(currNode->left);
        if (currNode->right) stack.push_back(currNode->right);
      }
      return retval;
    }
};
