class Solution {
  public:
    double myPow(double x, int n) {
      if (n == 0) return 1;
      if (n < 0) {
        if ((long)n <= (long)INT_MIN) {
          if (n % 2) n = INT_MAX;
          else n = INT_MAX-1;
        }
        else n = -n;
        x = 1/x;
      }
      return (n % 2 == 0) ? myPow(x*x, n/2) : x*myPow(x*x, n/2); 
    }
};
