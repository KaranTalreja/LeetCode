/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
  public:
    TreeNode* curr;
    vector<TreeNode*> stack;
    BSTIterator(TreeNode *root) : curr(root) {
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
      if (!stack.empty() || NULL != curr) return true;
      return false;
    }

    /** @return the next smallest number */
    int next() {
      TreeNode* retval = NULL;
      while (!stack.empty() || curr) {
        while (curr) {
          stack.push_back(curr);
          curr = curr->left;
        }
        retval = stack.back();
        curr = retval;
        stack.pop_back();
        curr = curr->right;
        break;
      }
      return retval ? retval->val : 0;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
