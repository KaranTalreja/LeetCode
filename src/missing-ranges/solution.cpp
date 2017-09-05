/*
Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

class Solution {
  public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
      vector<string> retval;
      int size = nums.size();
      int upperIdx = 0;
      long long lowerL = lower;
      long long upperL = upper;
      for (int i = 0; i < size; i++) {
        if (nums[i] == lowerL) {
          lowerL = (long long)nums[i]+1;
          while (upperIdx+1 < size && nums[upperIdx] == nums[upperIdx+1]) upperIdx++;
          upperIdx++;
        } else if (nums[i] > lowerL) {
          if ((long long)nums[upperIdx] != lowerL+1) retval.push_back(to_string(lowerL) + "->" + to_string(nums[upperIdx]-1));
          else retval.push_back(to_string(lowerL));
          lowerL = (long long)nums[i]+1;
          while (upperIdx+1 < size && nums[upperIdx] == nums[upperIdx+1]) upperIdx++;
          upperIdx++;
        }
      }
      if (lowerL == upperL) retval.push_back(to_string(lowerL));
      else if (lowerL < upperL) retval.push_back(to_string(lowerL) + "->" + to_string(upperL));
      return retval;
    }
};
