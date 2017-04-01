class Solution {
  public:
    int search(vector<int>& nums, int target) {
      int start = 0; int end = nums.size()-1;
      if (end < 0) return -1;
      while (end - start > 1) {
        int mid = (start+end)/2;
        if (nums[mid] == target) return mid;
        if (nums[start] < nums[end]) {
          if (target < nums[mid]) end = mid;
          else start = mid+1;
        } else {
          if (target < nums[mid]) {
            if (nums[mid] < nums[start]) end = mid;
            else if (target <= nums[end]) start = mid+1;
            else end = mid;
          } else {
            if (target > nums[start]) {
              if (nums[start] < nums[mid]) start = mid + 1;
              else end = mid; 
            } else if (target <= nums[end]) start = mid+1;
            else end = mid;
          }
        }
      }
      if (nums[start] == target) return start;
      if (nums[end] == target) return end;
      return -1;
    }
};
