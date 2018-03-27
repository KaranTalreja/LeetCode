class Solution {
  public:
    int trap(vector<int>& height) {
      int size = height.size();
      vector<int> maxLeft(size, 0);
      vector<int> maxRight(size, 0);
      int maxH = 0;
      for (int i = 0; i < size; i++) {
        maxLeft[i] = maxH;
        maxH = max(maxH, height[i]); 
      }
      maxH = 0;
      for (int i = size-1; i >=0; i--) {
        maxRight[i] = maxH;
        maxH = max(maxH, height[i]);
      }
      int retval = 0;
      for (int i = 0; i < size; i++) {
        int temp = min(maxLeft[i], maxRight[i]) - height[i];
        if (temp > 0) retval += temp;
      }
      return retval;
    }
};
