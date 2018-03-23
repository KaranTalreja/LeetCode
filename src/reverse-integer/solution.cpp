class Solution {
  public:
    int reverse(int x) {
      long retval = 0;
      while (x) {
        retval*=10;
        retval += (x % 10);
        x /= 10;
      }
      if (retval > INT_MAX || retval < INT_MIN) return 0;
      return retval;
    }
};
