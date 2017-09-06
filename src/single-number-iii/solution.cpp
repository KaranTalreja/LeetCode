class Solution {
  public:
    vector<int> singleNumber(vector<int>& nums) {
      int xorL = 0;
      vector<int> retval;
      int size = nums.size();
      for (int i = 0; i < size; i++) {
        xorL ^= nums[i];
      }
      int rightMost = (xorL) & ~(xorL-1);
      int a = 0,b = 0;
      for (int i = 0; i < size; i++) {
        if (nums[i] & rightMost) a ^= nums[i];
        else b ^= nums[i];
      }
      retval.push_back(a);
      retval.push_back(b);
      return retval;
    }
};
