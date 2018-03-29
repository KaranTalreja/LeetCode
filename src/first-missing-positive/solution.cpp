/*
We put each element in its rightful place. 

[3, 4, -1, 1] --> [-1, 4, 3, 1]
[-1, 4, 3, 1] --> [-1, 1, 3, 4] --> [1, -1, 3, 4]

Now -1 is not at its right position, so we return i+1 in the final loop

*/
class Solution {
  public:
    int firstMissingPositive(vector<int>& nums) {
      int size = nums.size();
      for (int i = 0; i < size; i++) {
        while (nums[i]-1 >= 0 && nums[i]-1 < size && nums[nums[i]-1] != nums[i]) {
          int temp = nums[nums[i]-1];
          nums[nums[i]-1] = nums[i];
          nums[i] = temp;
        }
      }
      for (int i = 0; i < size; i++) {
        if (nums[i] != i+1) return i+1;
      }
      return size+1;
    }
};
