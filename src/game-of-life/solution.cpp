class Solution {
  public:
    void gameOfLife(vector<vector<int>>& board) {
      int arr[][2] = {{-1,-1}, // top left
        {-1, 0}, // left
        {-1, 1}, // bottom left
        { 0, 1}, // bottom
        { 1, 1}, // bottom right
        { 1, 0}, // right
        { 1,-1}, // top right
        { 0,-1}};// top
      int m = board.size();
      int n = board[0].size();
      vector<vector<int>> copy(board);
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          int num_lives = 0;
          for (int k = 0 ; k < 8; k++) {
            int i_nbr = i + arr[k][0];
            int j_nbr = j + arr[k][1];
            if (i_nbr < 0 || i_nbr > m-1) continue;
            if (j_nbr < 0 || j_nbr > n-1) continue;
            num_lives += copy[i_nbr][j_nbr];
          }
          if (board[i][j] == 1) {
            if (num_lives < 2) board[i][j] = 0;
            else if (num_lives > 3) board[i][j] = 0;
          } else {
            if (num_lives == 3) board[i][j] = 1;
          }
        }
      }
    }
};
