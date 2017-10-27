class Solution {
  public:
    int getVal(string& s, int& i, bool first) {
      if (i < 0) return 0;
      int retval = 0;
      switch (s[i]) {
        case 'I': retval += 1;
                  break;
        case 'V': retval += 5;
                  break;
        case 'X': retval += 10;
                  break;
        case 'L': retval += 50;
                  break;
        case 'C': retval += 100;
                  break;
        case 'D': retval += 500;
                  break;
        case 'M': retval += 1000;
                  break;
      }
      int newI = i-1;
      int rc = getVal(s,newI, false);
      if (rc < retval) {
        retval -= rc;
        if (first == true) i--;
      }
      return retval;
    }

    int romanToInt(string s) {
      int size = s.size();
      if (!size) return 0;
      int retval = 0;
      for (int i = size-1; i >= 0; i--) {
        retval += getVal(s, i, true);
      }
      return retval;
    }
};
