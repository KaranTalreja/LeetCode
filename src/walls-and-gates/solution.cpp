/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/
class Solution {
  public:
    bool isValid (int r, int c, int& R, int& C, vector<vector<int>>& rooms, int level) {
      if (r < 0 || c < 0 || r >= R || c >= C) return false;
      if (rooms[r][c] == -1) return false;
      if (rooms[r][c] < level) return false;
      return true;
    }

    void wallsAndGates(vector<vector<int>>& rooms) {
      int R = rooms.size();
      if (!R) return;
      int C = rooms[0].size();
      vector<vector<int>> moves = {{0, 1},{1, 0},{-1, 0},{0, -1}};
      for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
          if (rooms[r][c] == 0) {
            queue<pair<int,int>> Q;
            Q.push(pair<int,int>(r,c));
            int level = 0;
            while (!Q.empty()) {
              int size = Q.size();
              for (int j = 0; j < size; j++) {
                pair<int,int> curr = Q.front();
                int r = curr.first;
                int c = curr.second;
                if (rooms[r][c] > level) rooms[r][c] = level;
                Q.pop();
                for (int i = 0; i < moves.size(); i++) {
                  if (isValid(r+moves[i][0] , c+moves[i][1], R, C, rooms, level+1)) {
                    Q.push(pair<int,int>(r+moves[i][0] , c+moves[i][1]));
                  }
                }   
              }
              level++;
            }
          }
        }
      }
    }
};
