class Solution {
  public:
    int searchInsert(vector<int>& nums, int target) {
      if (!nums.size()) return 0;
      int l = 0;
      int r = nums.size();
      while (r - l > 1) {
        int mid = l + (r-l)/2;
        if (nums[mid] <= target)
          l = mid;
        else
          r = mid;
      }
      if (nums[l] == target)  return l;
      if (l == 0) {
        if (target <= nums[0]) return 0;
        return 1;
      }
      return l+1;
    }
};
