class Solution {
  public:
    bool twoSum (vector<int>& nums, int target, int target_pos, int& min, int& curr_pair_sum) {
      int start = target_pos+1; int end = nums.size()-1;
      if (start == target_pos) start++;
      if (end == target_pos) end--;
      bool retval = false;
      while (end - start >= 1) {
        int curr_pair = nums[start] + nums[end];
        if (abs(target - curr_pair) < min) {
          min = abs(target - curr_pair);
          curr_pair_sum = curr_pair;
          retval = true;
        }
        if (curr_pair == target) {
          int temp_start = nums[start];
          int temp_end = nums[end];
          while (end - start >= 1 && nums[start] == temp_start) start++;
          while (end - start >= 1 && nums[end] == temp_end) end--;
          continue;
        } else if (target < curr_pair) end--;
        else start++;
        if (start == target_pos) start++;
        if (end == target_pos) end--;
      }
      return retval;
    }

    int threeSumClosest(vector<int>& nums, int target) {
      size_t size = nums.size();
      std::sort(nums.begin(), nums.end());
      int min = INT_MAX, retval = 0;
      if (size < 3) return retval;
      std::set<int> s;
      for (int i = 0; i < size; i++) {
        if (s.end() != s.find(target-nums[i])) continue;
        else s.insert(target-nums[i]);
        if (true == twoSum(nums, target-nums[i], i, min, retval))
          retval += nums[i];
      }
      return retval;
    }
};
