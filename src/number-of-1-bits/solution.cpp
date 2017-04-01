class Solution {
  public:
    int hammingWeight(uint32_t n) {
      int retVal = 0;
      while (n) {
        retVal += (n&0x01);
        n >>= 1;
      }
      return retVal;
    }
};
