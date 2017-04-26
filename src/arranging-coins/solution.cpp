class Solution {
  public:
    int arrangeCoins(int n) {
      if (n == 0) return 0;
      long r = n;
      long l = 1;
      while ( r - l > 1) {
        long m = l + (r-l)/2;
        if ((m*(1+m))/2 <= n)
          l = m;
        else
          r = m;
      }
      return l;
    }
};
