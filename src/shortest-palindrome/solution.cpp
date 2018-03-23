class Solution {
  public:

    string shortestPalindrome(string s) {
      string rev(s);
      if (!s.size()) return s;
      int end = s.size()-1;
      int start = 0;
      while (start < end) {
        char temp = rev[start];
        rev[start] = rev[end];
        rev[end] = temp;
        start++;
        end--;
      }
      int c = 0;
      int size = s.size();
      for (int i = 0; i < size; i++) {
        if (s.substr(0, size-i).find(rev.substr(i, size-i)) != std::string::npos) {
          c = i;
          break;
        }
      }
      s.insert(s.begin(), rev.begin(), rev.begin()+c);
      return s;
    }
};
