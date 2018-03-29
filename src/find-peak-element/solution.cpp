class Solution {
  public:
    int findPeakElement(vector<int>& nums) {
      if (nums.size() == 1) return 0;
      nums.insert(nums.begin(), INT_MIN);
      nums.push_back(INT_MIN);
      int start = 1;
      int end = nums.size()-2;
      while (start <= end) {
        int mid = start + (end-start)/2;
        if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid-1;
        else if (nums[mid] < nums[mid-1]) end = mid-1;
        else start = mid+1;
      }
      return -1;
    }
};

class Solution {
  public:
    long getVal(vector<int> nums, int idx, int size) {
      if (idx == -1) return (long)INT_MIN - 1;
      if (idx == size) return (long)INT_MIN - 1;
      return nums[idx];
    }

    int findPeakElement(vector<int>& nums) {
      int size = nums.size();
      if (size == 1) return size-1;
      for(int i = 0; i < size; i++) {
        if (getVal(nums,i,size) > getVal(nums,i+1,size) && getVal(nums,i,size) > getVal(nums,i-1,size)) return i;
      }
    }
};
