class Solution {
  public:
    int findUnsortedSubarray(vector<int>& nums) {
      if (nums.size() <= 1) return 0;
      int size = nums.size();
      int firstInversion = -1;
      int lastInversion = -1;
      for (int i = 0; i < size-1; i++) {
        if (nums[i] > nums[i+1]) {
          firstInversion = i;
          break;
        }
      }
      //cout << firstInversion << endl;
      if (firstInversion == -1) return 0;
      for (int i = size-1; i > 0; i--) {
        if (nums[i] < nums[i-1]) {
          lastInversion = i;
          break;
        }
      }
      //cout << lastInversion << endl; 
      if (lastInversion == -1) return 2;
      int max = INT_MIN, min = INT_MAX;
      for (int i = firstInversion; i <= lastInversion; i++) {
        if (nums[i] > max) max = nums[i];
        if (nums[i] < min) min = nums[i];
      }
      //cout << max << " " << min << endl;
      for (int i = 0; i < firstInversion; i++) {
        if (nums[i] > min) {
          firstInversion = i;
          break;
        }
      }

      for (int i = size-1; i > lastInversion; i--) {
        if (nums[i] < max) {
          lastInversion = i;
          break;
        }
      }
      return lastInversion - firstInversion + 1;
    }
};
