class Solution {
  public:
    bool canPermutePalindrome(string s) {
      vector<int> count (255, 0);
      int size = s.size();
      if (!size) return false;
      if (size == 1) return true;
      for (auto c : s) {
        count[c]++;
      }
      int countOdd = 0;
      for (auto c : count) {
        if (c % 2 == 1) countOdd++;
      }
      return countOdd > 1 ? false : true;
    }
};
