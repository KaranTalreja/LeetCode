class Solution {
  public:
    vector<int> findErrorNums(vector<int>& nums) {
      int n = nums.size();
      if (n < 2) return vector<int>();
      int xorS = 0;
      for (int i = 0; i < n; i++) xorS = (i+1) ^ xorS ^ nums[i];
      int firstBit = xorS & ~(xorS - 1);
      vector<int> retval(2,0);
      for (int i = 0; i < n; i++) {
        if (nums[i] & firstBit) retval[0] ^= nums[i];
        else retval[1]^= nums[i];
        if ((i+1) & firstBit) retval[0] ^= (i+1);
        else retval[1] ^= (i+1);
      }
      for (int i = 0; i < n; i++) {
        if (retval[1] == nums[i]) {
          int temp = retval[0];
          retval[0] = retval[1];
          retval[1] = temp;
          break;
        }
      }
      return retval;
    }
};
