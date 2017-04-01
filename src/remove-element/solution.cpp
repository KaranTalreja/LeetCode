class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
      int b;
      int length = nums.size();
      b = length -1;
      for (int i = 0; i <= b; i++) {
        if (nums[i] == val) {
          while (nums[b] == val) { b--; }
          if (b <= i) break;
          int temp = nums[i];
          nums[i] = nums[b];
          nums[b] = temp;
          b--;
        }
      }
      return b+1;
    }
};
