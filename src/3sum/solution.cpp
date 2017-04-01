class Solution {
  public:
    void twoSum (vector<int>& nums, int target, int target_pos, vector<vector<int>>& triplets) {
      int start = target_pos+1; int end = nums.size()-1;
      if (start == target_pos) start++;
      if (end == target_pos) end--;
      vector<int> retval;
      while (end - start >= 1) {
        int curr_pair = nums[start] + nums[end];
        if (curr_pair == target) {
          retval.push_back(-target);
          retval.push_back(nums[start]);
          retval.push_back(nums[end]);
          while (end - start >= 1 && nums[start] == retval[1]) start++;
          while (end - start >= 1 && nums[end] == retval[2]) end--;
          triplets.push_back(retval);
          retval.clear();
          continue;
        } else if (target < curr_pair) end--;
        else start++;
        if (start == target_pos) start++;
        if (end == target_pos) end--;
      }
      return;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
      size_t size = nums.size();
      std::sort(nums.begin(), nums.end());
      vector<vector<int>> retval;
      if (size < 3) return retval;
      std::set<int> s;
      for (int i = 0; i < size; i++) {
        if (s.end() != s.find(-nums[i])) continue;
        else s.insert(-nums[i]);
        twoSum(nums, -nums[i], i, retval);
      }
      return retval;
    }
};
