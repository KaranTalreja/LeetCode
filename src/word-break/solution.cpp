#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
class Solution {
  public:
    int searchDict (string s, vector<string>& wordDict) {
      for (int i = 0; i < wordDict.size(); i++) {
        if (!s.compare(wordDict[i])) {
          return 1;
        }
      }
      return 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
      int size = s.size();
      if (!size) return false;
      vector<int> dp(size,0);
      dp[0] = searchDict(s.substr(0,1), wordDict);
      for (int i = 1; i < size; i++) {
        for (int j = i-1; j >= 0; j--) {
          if (dp[j]) {
            dp[i] = searchDict(s.substr(j+1,i-j), wordDict);
            if(dp[i]) break;
          }
        }
        if (dp[i] == 0) dp[i] = searchDict(s.substr(0,i+1), wordDict);
      }
      return dp[size-1];
    }
};

int main() {
  string s = "iamatgoodamcodingcoding";
  vector<string> wordDict;
  wordDict.push_back("i");
  wordDict.push_back("am");
  wordDict.push_back("good");
  wordDict.push_back("at");
  wordDict.push_back("coding");
  Solution ans;
  cout << ans.wordBreak(s, wordDict) << endl; 
  return 0;
}
