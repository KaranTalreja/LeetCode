class Solution {
  public:
    int arrayPairSum(vector<int>& nums) {
      size_t size = nums.size();
      sort(nums.begin(), nums.end());
      int retval = 0;
      for (int i = 0; i < size; i+=2) {
        retval += nums[i];
      } 
      return retval;
    }
};
