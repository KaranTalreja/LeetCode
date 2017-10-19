/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.
*/
class Solution {
  public:
    bool getIthBit(int val, int i) {
      if (i == 0) return val & 0x1 ? true : false;
      return val & (1 << (i)) ? true : false;
    }

    int rangeBitwiseAnd(int m, int n) {
      int i = 0, j = 0;
      int M = m, N = n;
      if (M == N) return M;
      while (m) {
        i++;
        m >>= 1;
      }
      while (n) {
        j++;
        n >>= 1;
      }
      if (i == 0 || i != j) return 0;
      int retval = 0;
      for (--i; i >= 0; i--) {
        int a = getIthBit(M, i);
        int b = getIthBit(N,i);
        if (a != b) break;
        else retval = (retval << 1) | a;
      }
      if (i >= 0) retval <<= (i+1);
      return retval;
    }
};
