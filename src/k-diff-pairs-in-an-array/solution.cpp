// Join equivalent algo implemented as in DBMS
class Solution {
  public:
    int findPairs(vector<int>& nums, int k) {
      int size = nums.size();
      if (size <= 1) return 0;
      sort(nums.begin(), nums.end());
      int i = 0;
      int j = 0;
      int retval = 0;
      while (i < size && j < size) {
        //            cout << i << " " << j << endl;
        if (i == j) {j++; continue;}
        if (abs(nums[j] - nums[i]) < k) j++;
        else if (abs(nums[j] - nums[i]) == k) {
          //                cout << "I:"<< i << " " << j << endl;
          retval++;
          j++;
          while (j+1 < size && nums[j] == nums[j+1]) j++;
          // Special case when last entire array ahead of j matches with i
          if (abs(nums[j] - nums[i]) == k) j++;
        } else i++;
      }
      return retval;
    }
};
