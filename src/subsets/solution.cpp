class Solution {
  public:
    void helper(vector<int>& nums, int idx, vector<int> currSet, vector<vector<int>>& retval) {
      if (idx >= nums.size()) {
        retval.push_back(currSet);
        return;
      }
      helper(nums, idx+1, currSet, retval);
      currSet.push_back(nums[idx]);
      helper(nums, idx+1, currSet, retval);
      currSet.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int> currSet;
      vector<vector<int>> retval;
      helper(nums, 0, currSet, retval);
      return retval;
    }
};
