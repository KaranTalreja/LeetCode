#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    void compareCounts(int start, vector<int>& hashN, vector<int>& hashM, vector<int>& retval) {
      int i = 0;
      for (i = 0; i < 26; i++) {
        if (hashN[i] != hashM[i]) break;
      }
      if (i == 26) retval.push_back(start);
    }

    vector<int> findAnagrams(string s, string p) {
      vector<int> hashN(26, 0);
      vector<int> hashM(26, 0);
      int N = s.size();
      int M = p.size();
      vector<int> retval;
      for(int i = 0 ; i < M; i++) {
        hashN[s[i] - 'a']++;
        hashM[p[i] - 'a']++;
      }
      compareCounts(0, hashN, hashM, retval);
      for (int i = 1; i < N-M+1; i++) {
        hashN[s[i-1] - 'a']--;
        hashN[s[i+M-1] - 'a']++;
        compareCounts(i, hashN, hashM, retval);
      }
      return retval;
    }
};

int main() {
  string s = "cbaebabacb";
  string p = "abc";
  Solution ans;
  vector<int> result (ans.findAnagrams(s, p));
  for(int i = 0; i < result.size(); i++) cout << result[i] <<",";
  cout << endl;
  return 0;
}
