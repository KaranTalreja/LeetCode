class Solution {
  public:
    int mySqrt(int num) {
      long left = 0, right = num, mid;
      while (left <= right) {
        mid = (left + right)/2;
        if (mid*mid == num) return mid;
        else if (mid*mid < num) left = mid+1;
        else right = mid-1;
      }
      return right;
    }
};

class Solution {
  public:
    int mySqrt(int x) {
      size_t r = x;
      size_t l = 0;
      if (x == 1) return 1;
      while (r - l > 1) {
        size_t mid = l + (r-l)/2;
        if (mid * mid <= x) l = mid;
        else r = mid;
      }
      return l;
    }
};
