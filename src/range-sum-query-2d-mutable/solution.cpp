/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/
class NumMatrix {
  public:
    vector<vector<int>> data;
    vector<vector<int>> binaryIdxTree;
    int r, c;

    void updateTree(int x, int y, int val) {
      for (int i = x; i <= r ; i += i & (-i)) {
        for (int j = y; j <= c; j += j &(-j)) {
          binaryIdxTree[i][j] += val;   
        }
      }
    }

    int queryTree(int x, int y) {
      int retval = 0;
      for (int i = x; i > 0 ; i -= i & (-i)) {
        for (int j = y; j > 0 ; j -= j & (-j)) {
          retval += binaryIdxTree[i][j];
        }
      }
      return retval;
    }

    NumMatrix(vector<vector<int>> matrix) : data(matrix) {
      r = matrix.size();
      if (!r) return;
      c = matrix[0].size();
      binaryIdxTree = vector<vector<int>>(r+1, vector<int>(c+1, 0));
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          updateTree(i+1, j+1, data[i][j]);
        }
      }
    }

    void update(int row, int col, int val) {
      if (row < 0 || row >= r || col < 0 || col >= c) return;
      int diff = val - data[row][col];
      data[row][col] = val;
      updateTree(row+1, col+1, diff);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
      return queryTree(row2+1, col2+1) - queryTree(row2+1, col1) - queryTree(row1, col2+1) + queryTree(row1, col1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
