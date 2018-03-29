class Solution {
  public:

    int findUpper (vector<int>& nums, int target) {
      int start = 0;
      int end = nums.size();
      if (!end) return -1;
      while (end - start > 1) {
        int mid = start + (end-start)/2;
        if (nums[mid] <= target) start = mid;
        else end = mid;
      }
      if (nums[start] == target) return start;
      return -1;
    }

    int findLower(vector<int>& nums, int target) {
      int start = -1;
      int end = nums.size()-1;
      if (end < 0) return -1;
      while (end - start > 1) {
        int mid = start + (end-start)/2;
        if (nums[mid] >= target) end = mid;
        else start = mid;
      }
      if (nums[end] == target) return end;
      return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> retval;
      retval.push_back(findLower(nums, target));
      retval.push_back(findUpper(nums, target));
      return retval;
    }
};
