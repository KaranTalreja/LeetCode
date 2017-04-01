class Solution {
  public:
    vector<int> findDuplicates(vector<int>& nums) {
      size_t size = nums.size();
      std::vector<int> retval;
      for (size_t i =0; i < size; i++) {
        if (nums[i] < 0) {
          if (nums[-1*nums[i]-1] < 0) retval.push_back(-1*nums[i]);
          else nums[-1*nums[i]-1]*= -1;
        }
        else {
          if (nums[nums[i]-1] < 0) retval.push_back(nums[i]);
          else nums[nums[i]-1] *= -1;
        }
      }
      return retval;
    }
};
