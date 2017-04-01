class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
      uint32_t retVal = 0;
      for (int i = 0; i < 32; i++) {
        retVal >>= 1;
        retVal |= n & 0x80000000;
        n <<= 1;
      }
      return retVal;
    }
};
