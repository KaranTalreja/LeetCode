class Solution {
  public:
    class Trie {
      public:
        vector<Trie*> children;
        bool isWord;
        Trie() : children(26 ,NULL) , isWord(false) {}
        void insertHelper(Trie* root, string& s, int idx) {
          if (idx == s.size()) {
            root->isWord = true;
            return;
          }
          if (root->children[s[idx] - 'a'] == NULL) root->children[s[idx]-'a'] = new Trie();
          insertHelper(root->children[s[idx] - 'a'], s, idx+1);
        }

        void insert (string& s) {
          insertHelper(this, s, 0);
        }

        bool searchHelper(Trie* root, string& s, int idx) {
          if (!root) return false;
          if (idx == s.size()) {
            return root->isWord;
          }
          return searchHelper(root->children[s[idx]-'a'], s, idx+1);
        }

        bool search(string s) {
          return searchHelper(this, s, 0);
        }

    };

    void DFS(string& orig, string& currStr, vector<string>& retval, vector<pair<bool, vector<int>>>& DP, int idx) {
      if (idx < 0) {
        if (currStr.empty()) currStr = orig;
        retval.push_back(currStr);
        return;
      }
      if (DP[idx].first == false) return;
      for (auto o : DP[idx].second) {
        string temp(currStr);
        if (!currStr.empty()) currStr = orig.substr(idx - o + 1, o) + " " + currStr;
        else currStr = orig.substr(idx - o + 1, o);
        DFS(orig, currStr, retval, DP, idx - o);
        currStr = temp;
      }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
      vector<string> retval;
      int N = wordDict.size();
      int M = s.size();
      if (!M) return retval;
      if (!N) return retval;
      Trie* root = new Trie;
      for (auto w : wordDict) root->insert(w);        
      vector<pair<bool, vector<int>>> DP(M);
      for (int i = 0; i < M; i++) {
        for (int j = i-1; j >= 0; j--) {
          if (DP[j].first == true && root->search(s.substr(j+1, i-j)) == true) {
            DP[i].first = true;
            DP[i].second.push_back(i-j);
          }
        }
        if (root->search(s.substr(0,i+1)) == true) {
          DP[i].first = true;
          DP[i].second.push_back(i+1);
        }
      }
      // for (auto p : DP) {
      //   cout << p.first << ":";
      //   for (auto v : p.second) cout << v << " ";
      //   cout << endl;
      // }
      string currStr;
      DFS(s, currStr, retval, DP, M-1);
      return retval;
    }
};
