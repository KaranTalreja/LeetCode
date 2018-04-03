#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <limits.h>
#include <queue>

using namespace std;

class Solution {
  public:
    class Trie {

      vector<Trie*> children;
      public:
      Trie() : children(26, NULL) {

      }
      void insert(string& s){
        this->insertHelper(this, s, 0);
      }
      void insertHelper(Trie* root, string& s, int idx) {
        if (s.size() == idx) return;
        if (root->children[s[idx] - 'a'] == NULL) {
          root->children[s[idx] - 'a'] = new Trie();
        }
        insertHelper(root->children[s[idx] - 'a'], s, idx+1);
      }

      bool search (string& s) {
        return this->searchHelper(this, s, 0);
      }

      bool searchHelper(Trie* root, string& s, int idx) {
        if (s.size() == idx) return true;
        if (root->children[s[idx]-'a'] == NULL) return false;
        return searchHelper(root->children[s[idx] - 'a'], s, idx+1);
      }
    };

    int BFS(string& start, string& end, Trie* root, unordered_set<string>& visited) {
      int level = 1;
      queue<string> Q;
      Q.push(start);
      while (!Q.empty()) {
        int size = Q.size();
        for (int k = 0; k < size; k++) {
          string curr = Q.front();
          if (visited.find(curr) != visited.end()) {
            Q.pop();
            continue;
          }
          visited.insert(curr);
          Q.pop();
          if (curr == end) return level;
          for (int i = 0; i < curr.size(); i++) {
            for (int j = 0; j < 26; j++) {
              if (curr[i] == 'a'+j) continue;
              char temp = curr[i];
              curr[i] = 'a'+j;
              if (visited.find(curr) == visited.end() && root->search(curr) == true) {
                Q.push(curr);
              }
              curr[i] = temp;
            }
          }
        }
        level++;
      }
      return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
      Trie* root = new Trie();
      for (auto s : wordList) { root->insert(s); }
      unordered_set<string> visited;
      return BFS(beginWord, endWord, root, visited);
    }
};

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
