/*
On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.


Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.

Example:
Input: 3, 2, 0, 0
Output: 0.0625
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
Note:
N will be between 1 and 25.
K will be between 0 and 100.
The knight always initially starts on the board.
*/

class Solution {
  public:
    bool isValid (int& N, int r, int c) {
      if (r < 0 || c < 0 || r >= N || c >= N) return false;
      return true;
    }

    double knightProbability(int N, int K, int r, int c) {
      if (N == 0 || !isValid(N,r,c)) return 0.0;
      if (K == 0) return 1.0;
      double retval = 0.0;
      vector<vector<vector<double>>> DP(N, vector<vector<double>>(N, vector<double>(K+1,0.0)));
      static vector<vector<int>> options = {{2, 1},{2, -1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
      for (int k = 0; k <= K; k++) {
        for (int r = 0; r < N; r++) {
          for (int c = 0; c < N; c++) {
            if (k == 0) DP[r][c][k] = 1.0;
            else {
              for (int i = 0; i < options.size(); i++) {
                if (isValid(N, r+options[i][0], c+options[i][1])) {
                  DP[r][c][k] += 0.125 * DP[r+options[i][0]][c+options[i][1]][k-1];
                }
              }
            }
          }
        }
      }
      return DP[r][c][K];
    }
};
