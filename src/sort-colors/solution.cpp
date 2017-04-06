class Solution {
  public:
    void sortColors(vector<int>& nums) {
      int colors[3] = {0};
      int size = nums.size();
      for (int i = 0; i < size; i++) colors[nums[i]]++;
      colors[1] += colors[0];
      colors[2] += colors[1];
      int j = 0;
      for (int i = 0; i < 3; i++) {
        for (; j < colors[i]; j++) {
          nums[j] = i;
        }
      }
    }
};
