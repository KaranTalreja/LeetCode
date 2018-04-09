class Solution {
  public:
    struct TreeNode {
      TreeNode* lesser, *equal, *greater;
      int numElements;
      int val;
      TreeNode(int val) : numElements(1), val(val), lesser(NULL), equal(NULL), greater(NULL) {}
    };
    int getDepth (TreeNode* root) {
      if (root == NULL) return 0;
      return root->numElements;
    }
    TreeNode* insert(TreeNode* root, int val, int& retval) {
      if (!root) {
        return new TreeNode(val);;
      }
      if (val > root->val) root->greater = insert(root->greater, val, retval);
      else if (val == root->val) root->equal = insert(root->equal, val, retval);
      else root->lesser = insert(root->lesser, val, retval);
      root->numElements = 1 + getDepth(root->lesser) + getDepth(root->greater) + getDepth(root->equal);
      if (val > root->val) retval += 1 + getDepth(root->lesser) + getDepth(root->equal);
      if (val == root->val) retval += getDepth(root->lesser);
      return root;
    }

    vector<int> countSmaller(vector<int>& nums) {
      int N = nums.size();
      vector<int> retval(N, 0);
      if (!N) return retval;
      TreeNode* root = NULL;
      for (int i = N-1; i >= 0; i--) {
        int rc = 0;
        root = insert(root, nums[i], rc);
        retval[i] = rc;
      }
      return retval;
    }
};
