class Solution {
  public:
    bool isAnagram(string s, string t) {
      vector<int> hashS(26,0);
      vector<int> hashT(26,0);
      int sSize = s.size();
      int tSize = t.size();
      if (sSize != tSize) return false;
      for (int i = 0; i < sSize; i++) {
        hashS[s[i] - 'a']++;
        hashT[t[i] - 'a']++;
      }
      for (int i = 0; i < 26; i++) {
        if (hashS[i] != hashT[i]) return false;
      }
      return true;
    }
};
