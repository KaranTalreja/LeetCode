class TicTacToe {
  public:
    /** Initialize your data structure here. */
    vector<vector<int>>  board;
    int size;
    TicTacToe(int n) : board(vector<vector<int>>(n, vector<int>(n, 0))), size(n) {
    }

    bool isOver(int& player, vector<vector<int>>& board, int& row, int& col) {
      int count = 0;
      for (int i = row, j = 0; j < size; j++) {
        if (board[i][j] == player) count++;
      }
      if (count == size) return true;
      count = 0;
      for (int i = 0, j = col; i < size; i++) {
        if (board[i][j] == player) count++;
      }
      if (count == size) return true;
      count = 0;
      int r = row - min(row,col);
      int c = col - min(row,col);
      for (r, c; r < size && c < size; r++, c++) {
        if (board[r][c] == player) count++;
      }
      if (count == size) return true;
      count = 0;
      for (r = row, c = col; r >= 0 && c < size; r--, c++) {
        if (board[r][c] == player) count++;
      }
      count -= 1;
      for (r = row, c = col; c >= 0 && r < size; c--, r++) {
        if (board[r][c] == player) count++;
      }
      if (count == size) return true;
      return false;
    }

    /** Player {player} makes a move at ({row}, {col}).
      @param row The row of the board.
      @param col The column of the board.
      @param player The player, can be either 1 or 2.
      @return The current winning condition, can be either:
0: No one wins.
1: Player 1 wins.
2: Player 2 wins. */
    int move(int row, int col, int player) {
      board[row][col] = player;
      if (isOver(player, board, row, col)) return player;
      return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
