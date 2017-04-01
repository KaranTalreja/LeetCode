class Solution {
  public:
    int max3 (int a, int b, int c) {
      int max = a;
      if (b > max) max = b;
      if (c > max) max = c;
      return max;
    }
    int min3 (int a, int b, int c) {
      int min = a;
      if (b < min) min = b;
      if (c < min) min = c;
      return min;
    }
    int maxProduct(vector<int>& nums) {
      size_t size = nums.size();
      if (size == 0) return 0;
      if (size == 1) return nums[0];
      int max = nums[0];
      int curr_max = nums[0], prev_max = curr_max;
      int curr_min = nums[0], prev_min = curr_min;
      for (int i = 1; i < size; i++) {
        curr_max = max3 (prev_max*nums[i],
            prev_min*nums[i],
            nums[i]);
        curr_min = min3 (prev_max*nums[i],
            prev_min*nums[i],
            nums[i]);
        prev_max = curr_max;
        prev_min = curr_min;
        if (curr_max > max) max = curr_max;
      }
      return max;
    }
};
