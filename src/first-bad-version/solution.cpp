// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
  public:
    int firstBadVersion(int n) {
      int l = 0;
      int r = n;
      while (r - l > 1) {
        int m = l + (r-l)/2;
        if (isBadVersion(m) == true)
          r = m;
        else
          l = m;
      }
      return r;
    }
};
