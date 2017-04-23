class Solution {
  public:
    string reverseWords(string s) {
      if (s.empty()) return s;
      int size = s.size();
      int word_start = -1;
      int word_end = -1;
      for (int start = 0; start <= size; start++) {
        if (start == size) word_end = size-1;
        if (word_start == -1 && s[start] != ' ') word_start = start;
        if (word_end == -1 && s[start] == ' ') word_end = start-1;
        if (word_start != -1 && word_end != -1) {
          while (word_start < word_end) {
            char temp = s[word_start];
            s[word_start] = s[word_end];
            s[word_end] = temp;
            word_start++;
            word_end--;
          }
          word_start = -1;
          word_end = -1;
        }
      }
      return s;
    }
};
