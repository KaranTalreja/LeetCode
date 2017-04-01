class Solution {
  public:
    int missingNumber(vector<int>& nums) {
      size_t size = nums.size();
      size_t xor_i = 0;
      int i = 0;
      for (i = 0; i < size; i++) {
        xor_i = xor_i ^ i ^ nums[i];
      }
      return xor_i ^ i;
    }
};
