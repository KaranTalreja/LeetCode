class Solution {
  public:
    bool isValid(int i, int j, int& M, int& N, vector<vector<bool>>& visited) {
      if (i < 0 || i >= M || j < 0 || j >= N) return false;
      if (visited[i][j] == false) return true; 
      return false;
    }

    bool helper(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int idx, int i, int j, int& M, int& N) {
      static const vector<vector<int>> options = {{0, 1},{0, -1},{1, 0},{-1, 0}};
      if (idx == word.size()) return true;
      bool rc = false;
      for (auto o : options) {
        if (isValid(i + o[0], j + o[1], M, N, visited) && word[idx] == board[i + o[0]][j + o[1]]) {
          visited[i + o[0]][j + o[1]] = true;
          rc = helper(board, visited, word, idx+1, i + o[0], j + o[1], M, N);
          visited[i + o[0]][j + o[1]] = false;
          if (rc) return rc;
        } 
      }
      return rc;
    }

    bool exist(vector<vector<char>>& board, string word) {
      int size = word.size();
      if (!size) return true;
      int M = board.size();
      if(!M) return false;
      int N = board[0].size();
      vector<vector<bool>> visited(M, vector<bool>(N, false));
      bool rc = false;
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
          if (board[i][j] == word[0]) {
            visited [i][j] = true;
            rc = helper(board, visited, word, 1, i, j, M, N);
            visited[i][j] = false;
            if (rc) return rc;
          }
        }
      }
      return rc;
    }
};
