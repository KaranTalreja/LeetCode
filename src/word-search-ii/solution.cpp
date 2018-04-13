class Solution {
  public:
    class Trie {
      public:
        vector<Trie*> children;
        bool isWord;
        Trie ():children(26), isWord(false){}
        void insertHelper(Trie* root, string& s, int idx) {
          if (idx == s.size()) {
            root->isWord = true;
            return;
          }
          if (NULL == root->children[s[idx] - 'a']) root->children[s[idx] - 'a'] = new Trie();
          insertHelper(root->children[s[idx] - 'a'], s, idx+1);
        }

        bool searchHelper(Trie* root, string& s, int idx) {
          if (root == NULL) return false;
          if (idx == s.size()) {
            return root->isWord;
          }
          searchHelper(root->children[s[idx]-'a'], s, idx+1);
        }

        void insert(string& s) {
          insertHelper(this, s, 0);
        }

        bool search(string s) {
          return searchHelper(this, s, 0);
        }
    };
    bool isValid(int i, int j, int& R, int &C, vector<vector<bool>>& visited) {
      if (i < 0 || i >= R || j < 0 || j >= C) return false;
      return !visited[i][j];
    }

    void helper (vector<vector<char>>& board, int i, int j, int& R, int& C, string& s, Trie* root, vector<string>& retval, vector<vector<bool>>& visited) {
      if (root->isWord) {
        retval.push_back(s);
        root->isWord = false;
      }
      static vector<vector<int>> options = {{0,1},{0,-1},{1,0},{-1,0}};
      for (int c = 0; c < 26; c++) {
        if (root->children[c] == NULL) continue;
        for (auto o : options) {
          int x = i + o[0];
          int y = j + o[1];
          if (isValid(x, y, R, C, visited) && board[x][y] == c+'a') {
            visited[x][y] = true;
            s += ('a'+c);
            helper(board, x, y, R, C, s, root->children[c], retval, visited);
            s.pop_back();
            visited[x][y] = false;
          }
        }    
      }

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      vector<string> retval;
      int M = words.size();
      if (!M) return retval;
      int R = board.size();
      if (!R) return retval;
      int C = board[0].size();
      Trie* root = new Trie();
      vector<vector<bool>> visited(R, vector<bool>(C, false));
      for (auto s : words) root->insert(s);
      string curr;
      curr.reserve(R*C);
      for (int c = 0; c < 26; c++) {
        if (root->children[c] == NULL) continue;
        for (int i = 0; i < R; i++) {
          for (int j = 0; j < C; j++) {
            if ('a'+c == board[i][j]) {
              visited[i][j] = true;
              curr += ('a'+c);
              helper(board, i, j, R, C, curr, root->children[c], retval, visited);
              curr.pop_back();
              visited[i][j] = false;
            }
          }
        }
      }
      return retval;
    }
};
