class Solution {
  public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
      int size=s.size();
      if (!size) return 0;
      int distinct = 0;
      vector<int> hash(256,0);
      int retval = INT_MIN;
      int j = 0;
      for (int i = 0; i < size; i++) {
        if (hash[s[i]] == 0) distinct++;
        hash[s[i]]++;
        if (distinct > 2) {
          for (j ; j < i && distinct > 2; j++) {
            if (hash[s[j]] - 1 == 0) distinct--;
            hash[s[j]]--;
          }
        }
        if (retval < i-j+1) retval = i-j+1;
      }
      return retval;
    }
};
