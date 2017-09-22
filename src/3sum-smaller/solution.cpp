/*
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]
Follow up:
Could you solve it in O(n2) runtime?
*/
class Solution {
  public:
    void twoSumSmaller (vector<int>& nums, int target, int idx, int& retval ) {
      int size = nums.size();
      int j = size-1;
      int i = idx+1;
      while (i < j) {
        int temp = nums[i] + nums[j];
        if (temp < target) {
          retval+=j-i;
          i++;
        }
        else j--;
      }
    }

    int threeSumSmaller(vector<int>& nums, int target) {
      int size = nums.size();
      if (size < 3) return 0;
      int retval = 0;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < size; i++) {
        twoSumSmaller(nums, target-nums[i], i, retval);
      }
      return retval;
    }
};
