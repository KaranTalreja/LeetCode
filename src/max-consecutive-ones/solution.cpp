class Solution {
  public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int n = nums.size();
      int start=-1, end=-1, max = 0;
      for (int i = 0; i < n ; i++) {
        if (start == -1 && nums[i] == 1) {
          start = i;
          end = i;
        }
        else if (start != -1 && nums[i] == 1) {
          end = i;
        }
        else if (nums[i] == 0) {
          if(max <  end - start + 1 && start != -1) max = end - start + 1;
          end = -1;
          start = -1;
        }
      }
      if(max <  end - start + 1 && start != -1) max = end - start + 1;
      return max;
    }
};
