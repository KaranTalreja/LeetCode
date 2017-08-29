class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
      int size = s.size();
      if (size <= 1) return false;
      bool retval = false;
      for (int subStrL = 1; subStrL <= size/2; subStrL++) {
        if (size % subStrL) continue;        
        int numReps = size / subStrL;
        bool rc = true;
        for(int i = 0; i < size - 2*subStrL + 1; i+=subStrL) {
          //cout << s.substr(i,subStrL) << " " << s.substr(i+subStrL, subStrL) << endl;
          if (s.substr(i,subStrL).compare(s.substr(i+subStrL, subStrL))) { rc = false; break;}
        }
        retval = rc;
        if (retval) return retval;
      }
      return retval;
    }
};
