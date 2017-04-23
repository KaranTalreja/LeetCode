class Solution {
  public:
    string reverseString(string s) {
      if (s.empty()) return s;
      int start = 0;
      int end = s.size()-1;
      while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
      }
      return s;
    }
};
