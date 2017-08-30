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
    int helper (TreeNode* root, map<int,int>& sumFreqHash) {
      if (NULL == root) return 0;
      int lSum = helper(root->left, sumFreqHash);
      int rSum = helper(root->right, sumFreqHash);
      map<int,int>::iterator itr = sumFreqHash.find(lSum + rSum + root->val);
      if (itr == sumFreqHash.end()) {
        sumFreqHash[lSum + rSum + root->val] = 1;
      } else {
        itr->second++;
      }
      return lSum + rSum + root->val;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
      map<int, int> sumFreqHash;
      helper(root, sumFreqHash);
      map<int, int>::iterator start = sumFreqHash.begin();
      vector<int> retval;
      int maxFreq = INT_MIN;
      for (start; start != sumFreqHash.end(); start++) {
        if (start->second > maxFreq) {
          retval.clear();
          maxFreq = start->second;
          retval.push_back(start->first);
        }
        else if (start->second == maxFreq) {
          retval.push_back(start->first);
        }
      }
      return retval;
    }
};
