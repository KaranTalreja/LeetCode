/*
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
*/

class Solution {
  public:
    void wiggleSort(vector<int>& nums) {
      int size = nums.size();
      if (!size) return;
      int temp;
      for (int i = 1; i < size; i+=2) {
        if (nums[i] < nums[i-1]) {
          temp = nums[i];
          nums[i] = nums[i-1];
          nums[i-1] = temp;
        }
        if (i+1 < size && nums[i] < nums[i+1]) {
          temp = nums[i];
          nums[i] = nums[i+1];
          nums[i+1] = temp;
        }
      }
      return;
    }
};
