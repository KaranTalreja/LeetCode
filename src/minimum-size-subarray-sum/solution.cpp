class Solution {
  public:
    int minSubArrayLen(int s, vector<int>& nums) {
      int start=0, end=0;
      size_t size = nums.size();
      if (size == 0) return 0;
      int cumulative = nums[0];
      int retval_min = size+1;
      while (start <= end && end < size) {
        if (cumulative >= s) {
          if (retval_min > end - start + 1) retval_min = end - start + 1;
          cumulative -= nums[start];
          start++;
        } else {
          end++;
          if (end == size) break;
          cumulative += nums[end];
        }
      }
      return retval_min == size+1 ? 0 : retval_min;
    }
};
