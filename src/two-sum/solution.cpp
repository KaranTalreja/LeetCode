class Solution {
  public:

    int binarySearch(vector<int>& nums, int key, int begin, int end) {
      if (begin > end) return -1;
      int mid = (begin + end) / 2;
      if (nums[mid] == key) return mid;
      else if (mid == begin) return -1;
      if (nums[mid] > key) return binarySearch(nums, key, begin, mid);
      else return binarySearch(nums, key, mid+1, end);
    }

    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> retval(2);
      vector<int> copy(nums.size());
      for (int i = 0; i < nums.size(); i++) {
        copy[i] = nums[i];
      }
      sort(nums.begin(), nums.end());
      for (int i =0; i< nums.size(); i++) {
        int idx = binarySearch(nums, target - nums[i], 0, nums.size()-1);
        if (idx != -1 && idx != i) {
          int a = -1,b = -1;
          for (int j = 0; j < nums.size(); j++) {
            if (copy[j] == nums[i] && a == -1) a = j;
                    else if (copy[j] == nums[idx] && b == -1) b = j;
                }
                retval[0] = a < b ? a : b;
                retval[1] = a < b ? b : a;
                return retval;
            }
        }
        return retval;
    }
};
