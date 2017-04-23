class Solution {
  public:
    string reverseStr(string s, int k) {
      if (s.empty()) return s;
      int size = s.size()-1;
      int start = 0;
      int end = k-1 < size ? k-1 : size;
      int prev_start = start;
      int prev_end = end;
      while (start < end) {
        while (start < end) {
          char temp = s[start];
          s[start] = s[end];
          s[end] = temp;
          start++;
          end--;
        }
        prev_start += 2*k;
        prev_end += 2*k;
        start = prev_start < size ? prev_start : size;
        end = prev_end < size ? prev_end : size;
      }
      return s;
    }
};
