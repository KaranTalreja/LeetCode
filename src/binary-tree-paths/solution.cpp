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
    char buffer[100];
    void helper(TreeNode* root, vector<string>& stack, std::string path) {
      if (NULL == root) return;
      if (path.empty()) {
        sprintf(buffer,"%d", root->val);
        path = std::string(buffer);
      } else {
        sprintf(buffer,"->%d", root->val);
        path += std::string(buffer);
      }
      helper(root->left, stack, path);
      helper(root->right, stack, path);
      if (root->left == NULL && root->right == NULL) stack.push_back(path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> retval;
      helper(root, retval, std::string(""));
      return retval;
    }
};
