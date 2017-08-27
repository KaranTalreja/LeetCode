class Solution {
  public:
    void clearHash(vector<pair<int, int>>& hash) {
      for (int i = 0; i < 255; i++) {
        hash[i].first = 0;
        hash[i].second = 0;
      }
    }
    int lengthOfLongestSubstring(string s) {
      vector<pair<int,int>> hash(255,pair<int,int>(0,0));
      int retval = 0;
      int size = s.size();
      if (!size) return retval;
      int currLen = 0;
      for (int i = 0; i < size; i++) {
        if (hash[s[i]].first != 0) {
          currLen = 0;
          i = hash[s[i]].second+1;
          clearHash(hash);
        }
        currLen++;
        hash[s[i]].first++;
        hash[s[i]].second = i;
        if (currLen > retval) retval = currLen;
      }
      return retval;
    }
};
