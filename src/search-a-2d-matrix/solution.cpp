class Solution {
  public:
    bool binarySearch (vector<int>& nums, int target, int start, int end) {
      while (end - start > 1) {
        int mid = (start + end) / 2;
        if (target >= nums[mid])  start = mid;
        else end = mid;
      }
      if (nums[start] == target) return true;
      if (nums[end] == target) return true;
      return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      size_t size = matrix.size();
        if (size == 0 || matrix[0].size() == 0) return false;
        int row = 0;
        for(row  = 0; row < size; row++) {
            if (matrix[row][0] > target) break;
        }
        if (row == 0) return false;
        row--;
        return binarySearch(matrix[row], target, 0 , matrix[row].size()-1);
    }
};
