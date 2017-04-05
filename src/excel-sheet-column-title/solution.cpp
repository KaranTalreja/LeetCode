class Solution {
  public:
    string convertToTitle(int n) {
      string retval = "";
      if (n == 0) return retval;
      if (n <= 26) retval += (char)((int)('A') + n - 1);
      else {
        if (n%26 != 0) retval = convertToTitle(n/26) + convertToTitle(n%26);
        else {
          retval = convertToTitle((n-1)/26) + convertToTitle(26);
        }
      }
      return retval;
    }
};
