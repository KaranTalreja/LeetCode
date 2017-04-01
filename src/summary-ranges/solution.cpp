class Solution {
  public:
    vector<string> summaryRanges(vector<int>& nums) {
      size_t size = nums.size();
      vector<string> retval;
      if (size == 0) return retval;
      int base = nums[0], prev = nums[0];
      char buffer[100];
      size_t i = 0;
      for (i = 0; i < size; i++) {
        if (nums[i] != prev+1) {
          if (base == nums[i]);
          else if (nums[i-1] - base) {
            sprintf(buffer, "%d->%d",base, nums[i-1]);
            retval.push_back(string(buffer));
            base = nums[i];
            prev = base;
          } else {
            sprintf(buffer, "%d",base);
            retval.push_back(string(buffer));
            base = nums[i];
            prev = base;
          }
        } else {
          prev = nums[i];
        }
      }
      if (nums[i-1] - base) {
        sprintf(buffer, "%d->%d",base, nums[i-1]);
        retval.push_back(string(buffer));
      } else {
        sprintf(buffer, "%d",base);
        retval.push_back(string(buffer));
      }
      return retval;
    }
};
