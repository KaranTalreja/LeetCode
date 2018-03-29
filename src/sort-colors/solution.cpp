class Solution {
  public:
    void swap(int& a, int& b) {
      int temp = a;
      a = b;
      b = temp;
    }

    void sortColors(vector<int>& nums) {
      int size = nums.size();
      int low = 0, mid = 0, high = size-1;
      while (mid <= high) {
        switch (nums[mid]) {
          case 0: {
                    swap(nums[low], nums[mid]);
                    low++;
                    mid++;
                  }
                  break;
          case 1: {
                    mid++;
                  } 
                  break;
          case 2: {
                    swap(nums[high], nums[mid]);
                    high--;
                  }
                  break;
        }
      }
    }
};

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
