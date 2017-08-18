#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
class Solution {
  public:
    int searchDict (string& s, int start, int end, vector<string>& wordDict, vector<vector<int> >& dp) {
      if (dp[start][end] != -1) return dp[start][end];
      for (int i = 0; i < wordDict.size(); i++) {
        if (!s.compare(start, end-start+1, wordDict[i])) {
          dp[start][end] = 1;
          return dp[start][end];
        }
      }
      dp[start][end] = 0;
      return dp[start][end];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
      int size = s.size();
      if (!size) return false;
      vector<vector<int> > dp(size, vector<int>(size, -1));
      for (int i = 0; i < size; i++){searchDict(s,i,i,wordDict,dp);}
      for (int L = 2; L <= size; L++) {
        for (int i = 0; i < size -L + 1; i++) {
          int j = i+L-1;
          //cout <<"Searching in " << s.substr(i, j-i+1) <<" " << i << "," << j << endl;
          searchDict(s, i,j, wordDict,dp);
          for (int k = i; k < j; k++) {
            //cout << s.substr(i, k-i+1);
            int lhs = searchDict(s,i,k,wordDict,dp);
            //cout << " : " << lhs << endl;
            //cout << s.substr(k+1, j-k); 
            int rhs = searchDict(s,k+1,j,wordDict,dp);
            //cout << " : " << rhs << endl;
            if (lhs == 1 && rhs == 1) {
              dp[i][j] = 1;
              break;
            }
          }
        }
      }
      return dp[0][size-1] == 1? true : false;
    }
};

int main() {
  string s = "leecode";
  vector<string> wordDict;
  wordDict.push_back("leet");
  wordDict.push_back("code");
  Solution ans;
  cout << ans.wordBreak(s, wordDict) << endl; 
  return 0;
}
