class Solution {
  public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      vector<int> zeros(3, -1);
      int size = nums.size();
      if (!size) return size;
      int max = 0;
      int maxC = 0;
      int rc = 0;
      for (int i = 0; i <= size; i++) {
        if (i == size || nums[i] == 0) {
          if (maxC < rc) maxC = rc;
          rc = 0;
          zeros[0] = zeros[1];
          zeros[1] = zeros[2];
          zeros[2] = i;
          if (zeros[1] != -1 && max < zeros[2] - zeros[0] - 1) max = zeros[2] - zeros[0] - 1;
        } else rc++;
      }

      return maxC > max ? maxC : max;
    }
};
