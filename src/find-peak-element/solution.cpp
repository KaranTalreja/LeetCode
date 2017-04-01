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
