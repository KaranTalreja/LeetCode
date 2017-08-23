#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int R = matrix.size();
      if (!R) return false;
      int C = matrix[0].size();
      int r = 0, c = C-1;
      while (r < R && c >= 0) {
        if (target == matrix[r][c]) return true;
        else if (target > matrix[r][c]) { r++; }
        else c--;
      }
      return false;
    }
};

int main() {
  vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
  for (int target = 1; target < 40; target++) {
    Solution ans;
    cout << target << " : "<<ans.searchMatrix(matrix, target) << endl;
  }
}
