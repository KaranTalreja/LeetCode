/*

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
class Solution {
  public:
    void swap(int& a, int& b) {
      int temp = a;
      a = b;
      b = temp;
    }

    void helper(vector<int>& nums, vector<vector<int>>& retval, int startIdx, int& size) {
      if (startIdx == size) {
        retval.push_back(nums);
        return;
      }
      for (int i = startIdx; i < size; i++) {
        swap(nums[i], nums[startIdx]);
        helper(nums, retval, startIdx+1, size);
        swap(nums[i], nums[startIdx]);
      }
    }

    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> retval;
      int size = nums.size();
      if (!size) return retval;
      helper(nums, retval, 0, size);
      return retval;
    }
};
