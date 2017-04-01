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
    void helper(TreeNode* root, map<int,int>& count, int& maxCnt) {
      if(root== NULL) return;
      map<int,int>::iterator itr = count.find(root->val);
      if (itr != count.end()) count[root->val] = count[root->val]+1;
      else    count[root->val] = 1;
      if (count[root->val] > maxCnt)  maxCnt = count[root->val];
      helper(root->left, count, maxCnt);
      helper(root->right, count, maxCnt);
      return;
    }

    vector<int> findMode(TreeNode* root) {
      map<int, int> count;
      int maxCnt = 0;
      vector<int> modes;
      helper(root, count, maxCnt);
      for (map<int, int>::iterator itr = count.begin(); itr != count.end(); itr++) {
        if (itr->second == maxCnt) modes.push_back(itr->first);
      }
      return modes;
    }
};
