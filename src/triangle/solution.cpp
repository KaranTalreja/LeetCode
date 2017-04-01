class Solution {
  public:
    int helper (vector<vector<int>>& triangle, int row, int column, size_t& max_rows, unordered_map<size_t, int>& cache) {
      if (row == max_rows - 1) {
        return triangle[row][column];
      }
      unordered_map<size_t, int>::iterator itr;
      int left_subtree_value, right_subtree_value;
      itr = cache.find((row+1)*(max_rows+1)+column);
      if (itr == cache.end()) {
        left_subtree_value = helper(triangle, row+1, column, max_rows, cache);
      } else left_subtree_value = itr->second;
      itr = cache.find((row+1)*(max_rows+1)+column+1);
      if (itr == cache.end()) {
        right_subtree_value = helper(triangle, row+1, column+1, max_rows, cache);
      } else right_subtree_value = itr->second;
      int retval = min(triangle[row][column] + left_subtree_value, triangle[row][column] + right_subtree_value);
      cache.insert(pair<size_t, int> ((row)*(max_rows+1)+column, retval));
      return retval;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
      size_t size = triangle.size();
      unordered_map<size_t,int> cache;
      return helper(triangle, 0, 0, size, cache);
    }
};
