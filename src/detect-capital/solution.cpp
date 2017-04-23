class Solution {
  public:
    bool allLowerCaseOrUpperCase(string word, int start, int end, bool onlyLower) {
      bool allLower = true;
      for (int i = start; i < end; i++) {
        if (word[i] >= 'a' && word[i] <= 'z') continue;
        allLower = false;
      }
      if (false == onlyLower) {
        bool allCaps = true;
        for (int i = start; i < end; i++) {
          if (word[i] >= 'A' && word[i] <= 'Z') continue;
          allCaps = false;
        }
        if (allLower == true || allCaps == true) return true;
        return false;
      }
      return allLower;
    }

    bool detectCapitalUse(string word) {
      int size = word.size();
      if (word[0] >= 'A' && word[0] <= 'Z') return allLowerCaseOrUpperCase(word, 1, size, false);
      return allLowerCaseOrUpperCase(word, 0, size, true);
    }
};
