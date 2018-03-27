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

class Solution {
  public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
      vector<string> retval;
      size_t size = nums.size();
      if (!size) {
        if (lower == upper) retval.push_back(to_string(lower));
        else retval.push_back(to_string(lower) + "->" + to_string(upper));
        return retval;
      }
      int j = 0;
      for (int i = 0; i < size; i++) {
        if (nums[i] != nums[j]) nums[++j] = nums[i];
      }
      size = j+1;
      for (int i = 0; i < size; i++) {
        if (nums[i] != ((i-1 >= 0) ? (long)nums[i-1]+1: lower)) {
          retval.push_back(i-1 >= 0 ? to_string((long)nums[i-1]+1) : to_string(lower));
          if ((nums[i]) - ((i-1 >= 0) ? nums[i-1] : (long)lower-1) > 2) {
            retval.back() += ("->" + to_string(((long)nums[i]-1))); 
          }
        } 
      }
      if (nums[size-1] != upper) {
        retval.push_back(to_string((long)nums[size-1]+1));
        if (upper > nums[size-1] + 1) {
          retval.back() += "->" + to_string(upper);
        }
      }
      return retval;
    }
};
