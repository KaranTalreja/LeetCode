class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.size() <= 1) return nums.size();
      int newIdx, oldIdx, length = nums.size();
      for (oldIdx=1, newIdx=1; oldIdx < length; oldIdx++) {
        if (nums[oldIdx] == nums[oldIdx-1]) continue;
        nums[newIdx++] = nums[oldIdx];
      }
      return newIdx;
    }
};
