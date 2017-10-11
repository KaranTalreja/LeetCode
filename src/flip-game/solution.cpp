class Solution {
  public:
    vector<string> generatePossibleNextMoves(string s) {
      vector<string> retval;
      int size = s.size();
      if (!size) return retval;
      int k = 2;
      for (int i = 0; i < size - k + 1; i++) {
        if (s[i] == '+' && s[i+1] == '+') {
          s[i] = '-';
          s[i+1] = '-';
          retval.push_back(s);
          s[i] = '+';
          s[i+1] = '+';
        }
      }
      return retval;
    }
};
