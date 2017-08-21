#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <limits.h>
#include <queue>

using namespace std;

class Solution {
  public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      int wordLength = beginWord.size();
      wordList.insert(wordList.begin(), beginWord);
      int dictSize = wordList.size();
      vector<vector<int>> graph(dictSize);
      for (int u = 0; u < dictSize; u++) {
        for (int v = 0; v < dictSize; v++) {
          if (u != v) {
            int parity = 0;
            for (int i = 0; i < wordLength; i++) {
              if (wordList[u][i] != wordList[v][i]) parity++;
            }
            if (parity == 1) graph[u].push_back(v);
          }
        }
      }
      queue<int> Q;
      Q.push(0);
      vector<bool> visited(dictSize, false);
      vector<long> jumps(dictSize, (long)INT_MAX);
      jumps[0] = 0;
      while (!Q.empty()) {
        int currWord = Q.front();
        visited[currWord] = true;
        Q.pop();
        for (int i = 0; i < graph[currWord].size(); i++) {
          if (visited[graph[currWord][i]] == false) {
            Q.push(graph[currWord][i]);
            if(jumps[graph[currWord][i]] > jumps[currWord] + 1) jumps[graph[currWord][i]] = jumps[currWord] + 1;
          }
        }
      }
      for (int i = 1; i < dictSize; i++) {
        if (wordList[i] == endWord) {
          if (visited[i]) return jumps[i]+1;
          return 0;
        }
      }
      return 0;
    }
};

int main() {
string beginWord = "hit";
string endWord = "cog";
vector<string> wordDict = {"hot","dot","dog","lot","log","cog"};

Solution ans;
cout << ans.ladderLength(beginWord, endWord, wordDict) << endl;
}
