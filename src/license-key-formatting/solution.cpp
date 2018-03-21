class Solution {
  public:
    string licenseKeyFormatting(string S, int K) {
      string retval;
      int size = S.size();
      if (!size) return retval;
      int count = 0;
      for (int i = size-1; i >=0; i--) {
        if (S[i] != '-') {
          retval += S[i];
          count ++;
          if (count == K) {
            retval += "-";
            count = 0;
          }
        }
      }
      for (int i = 0; i < retval.size(); i++) {
        retval[i] = toupper(retval[i]);
      }
      int i = 0;
      int j = retval.size()-1;
      if (retval[j] == '-') {
        retval.pop_back();
        j--;
      }
      while(i < j) {
        char temp = retval[i];
        retval[i] = retval[j];
        retval[j] = temp;
        i++;
        j--;
      }
      return retval;
    }
};
