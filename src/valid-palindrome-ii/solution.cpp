class Solution {
  public:
    bool isPalindrome(string& s, int start, int end) {
      while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
      }
      return true;
    }
    bool validPalindrome(string s) {
      int start = 0, end = s.size()-1;
      if (end <= 0) return true;
      bool skippedOne = false;
      while (start < end) {
        if (s[start] != s[end]) {
          if (skippedOne == true) return false;
          else skippedOne = true;
          bool rc = false;
          if (s[start] == s[end-1]) rc = isPalindrome(s, start, end-1);
          if (rc) return rc;
          if (s[start+1] == s[end]) start++;
          else return false;
          continue;
        }
        start++;
        end--;
      }
      return true;
    }
};
