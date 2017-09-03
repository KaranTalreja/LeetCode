/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
*/
class Solution {
  public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
      int max = INT_MIN;
      if (k <= 0) return k;
      if (k > s.size()) return s.size();
      int j = -1;
      vector<int> hash(256,0);
      int distinct = 0;
      for (int i = 0; i < s.size(); i++) {
        if (hash[s[i]] == 0) distinct++;
        hash[s[i]]++;
        while (distinct > k) {
          j++;
          if (--hash[s[j]] == 0) distinct--;
        }
        if (i-j > max) max = i-j;
      }
      return max;
    }
};
