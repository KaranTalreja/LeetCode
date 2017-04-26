class Solution {
  public:
    int countSegments(string s) {
      if (s.empty()) return 0;
      int start = 0;
      int end = s.size()-1;
      while (start <= end && s[start] == ' ') start++;
      while (start <= end && s[end] == ' ') end--;
      int count=0;
      bool seenNonSpace = false;
      for (start; start<=end;) {
        if (s[start] == ' ') {
          count++;
          while (start <= end && s[start] == ' ') start++;
        } else {
          start++;
          seenNonSpace = true;
        }
      }
      if (seenNonSpace == false) return 0;
      return count+1;
    }
};
