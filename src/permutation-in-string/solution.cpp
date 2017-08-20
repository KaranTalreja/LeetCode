class Solution {
  public:
    bool compareCounts(int start, vector<int>& hashN, vector<int>& hashM) {
      int i = 0;
      for (i = 0; i < 26; i++) {
        if (hashN[i] != hashM[i]) break;
      }
      if (i == 26) return true;
      return false;
    }

    bool checkInclusion(string s1, string s2) {
      vector<int> hashN(26, 0);
      vector<int> hashM(26, 0);
      int N = s2.size();
      int M = s1.size();
      for(int i = 0 ; i < M; i++) {
        hashN[s2[i] - 'a']++;
        hashM[s1[i] - 'a']++;
      }
      if (compareCounts(0, hashN, hashM)) return true;
      for (int i = 1; i < N-M+1; i++) {
        hashN[s2[i-1] - 'a']--;
        hashN[s2[i+M-1] - 'a']++;
        if (compareCounts(i, hashN, hashM)) return true;
      }
      return false;
    }
};
