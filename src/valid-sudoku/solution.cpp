class Solution {
  public:
    bool checkRow(int row, vector<vector<char>>& board) {
      vector<int> hash(9,0);
      for (int c = 0; c < 9; c++) {
        if (board[row][c] == '.') continue;
        else if (hash[board[row][c] - '1'] == 1) return false;
        hash[board[row][c] - '1'] = 1;
      }
      return true;
    }

    bool checkCol(int col, vector<vector<char>>& board) {
      vector<int> hash(9,0);
      for (int r = 0; r < 9; r++) {
        if (board[r][col] == '.') continue;
        else if (hash[board[r][col] - '1'] == 1) return false;
        hash[board[r][col] - '1'] = 1;
      }
      return true;
    }

    bool checkBox(int box, vector<vector<char>>& board) {
      vector<int> hash(9,0);
      int sRow = (box/3)*3;
      int sCol = (box%3)*3;
      for (int i = sRow; i < sRow+3; i++) {
        for (int j = sCol; j < sCol+3; j++) {
          if (board[i][j] == '.') continue;
          else if (hash[board[i][j] - '1'] == 1) return false;
          hash[board[i][j] - '1'] = 1;
        }
      }
      return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
      bool rc = true;
      for (int i = 0; i < 9; i++) {
        rc = checkRow(i, board);
        if (!rc) return rc;
      }
      for (int i = 0; i < 9; i++) {
        rc = checkCol(i, board);
        if (!rc) return rc;
      }
      for (int i = 0; i < 9; i++) {
        rc = checkBox(i, board);
        if (!rc) return rc;
      }
      return rc;
    }
};
