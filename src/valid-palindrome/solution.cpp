class Solution {
  public:
    bool isPalindrome(string s) {
      if (s.empty()) return true;
      std::transform(s.begin(), s.end(), s.begin(), ::tolower);
      int end = s.size()-1;
      int start = 0;
      while (start < end) {
        while (start < end && !(s[start] >= 'a' && s[start] <= 'z') && !(s[start] >= '0' && s[start] <= '9')) start++;
        if (start == end) continue;
        while (start < end && !(s[end] >= 'a' && s[end] <= 'z') && !(s[end] >= '0' && s[end] <= '9')) end--;
        if (start == end) continue;
        if (s[start] != s[end]) return false;
        start++;
        end--;
      }
      return true;
    }
};
