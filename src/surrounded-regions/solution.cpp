class Solution {
  public:
    bool isValid (int r, int c, int& M, int& N, vector<vector<char>>& board, vector<vector<bool>>& visited) {
      if (r < 0 || r >= M || c < 0 || c >= N) return false;
      if (board[r][c] == 'X' || visited[r][c] == true) return false;
      visited[r][c] = true;
      return true;
    }

    void solve(vector<vector<char>>& board) {
      int M = board.size();
      if (!M) return;
      int N = board[0].size();
      vector<vector<bool>> visited(M, vector<bool>(N, false));
      pair<int,int> temp;
      queue<pair<int,int>> Q;
      for (int i = 0; i < M; i++) {
        temp.first = i;
        temp.second = -1;
        Q.push(temp);
        temp.second = N;
        Q.push(temp);
      }
      for (int j = 0; j < N; j++) {
        temp.second = j;
        temp.first = -1;
        Q.push(temp);
        temp.first = M;
        Q.push(temp);
      }
      // for (auto r : board) {
      //   for (auto c : r) {
      //     cout << c << " ";
      //   }
      //   cout << endl;
      // }
      vector<vector<int>> options = {{-1,0}, {1,0}, {0,-1}, {0,1}};
      while (!Q.empty()) {
        int size = Q.size();
        for (int i = 0; i < size; i++) {
          temp = Q.front();
          Q.pop();
          for (auto o : options) {
            if (isValid(temp.first + o[0], temp.second + o[1], M, N, board, visited)) {
              pair <int, int> t (temp.first+o[0], temp.second + o[1]);
              Q.push(t);
            }
          }
        }
        // cout << endl;
        // for (auto r : visited) {
        //   for (auto c : r) {
        //     cout << c << " "; 
        //   }
        //   cout << endl;
        // }
      }
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
          if (visited[i][j] == false && board[i][j] == 'O')
            board[i][j] = 'X';
        }
      }
      // cout << endl;
      // for (auto r : board) {
      //   for (auto c : r) {
      //     cout << c << " ";
      //   }
      //   cout << endl;
      // }
    }
};
