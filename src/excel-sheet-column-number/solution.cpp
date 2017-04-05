class Solution {
  public:
    int titleToNumber(string s) {
      int length = s.size();
      int retval = 0;
      for (int i = length-1; i >= 0; i--) {
        retval += ((s[(length-1)-i] - (int)'A' + 1) * pow(26,i));
      }
      return retval;
    }
};
