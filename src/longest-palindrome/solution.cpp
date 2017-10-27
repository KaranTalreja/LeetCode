class Solution {
  public:
    int longestPalindrome(string s) {
      vector<int> count (255, 0);
      int size = s.size();
      if (!size) return 0;
      for (auto c : s) {
        count [c]++;
      }
      int retval = 0;
      bool oddFound = false;
      for (auto c : count) {
        if (c != 0 && c%2 == 0) retval+=c;
        else if (c != 0)  {
          oddFound = true;
          retval += c-1;
        }
      }
      return oddFound == true ? retval +1 : retval;
    }
};
