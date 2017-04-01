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
