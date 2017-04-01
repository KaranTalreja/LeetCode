class Solution {
  public:
    int majorityElementHelper (vector<int>& nums ,int begin, int end, bool& found) {
      if (end < begin) return 0;
      if (end == begin) {
        found = true;
        //      cout << begin << ":" << end << "=" << found << "," << nums[begin] << endl;
        return nums[begin];
      }
      int length = end - begin;
      bool foundL = false, foundR = false;
      int mjrL = majorityElementHelper (nums, begin, begin + length/2, foundL);
      int mjrR = majorityElementHelper (nums, begin + length/2 + 1, end, foundR);
      int retVal = 0;
      if (foundL == true && foundR == true && mjrL == mjrR) {
        retVal = mjrL;
        found = true;
      }
      else {
        if (foundL == true) {
          int countL = 0;
          for (int i = begin; i <= end; i++) {
            if (mjrL == nums[i]) countL++;
          }
          if (countL >= length/2 + 1) {
            retVal = mjrL;
            found = true;
          }
        }
        if (foundR == true) {
          int countR = 0;
          for (int i = begin; i <= end; i++) {
            if (mjrR == nums[i]) countR++;
          }
          if (countR >= length/2 + 1) {
            retVal = mjrR;
            found = true;
          }
        }
      }
      //      cout << begin << ":" << end << "=" << found << "," << retVal << endl;
      return retVal;
    }

    int majorityElement(vector<int>& nums) {
      bool found = false;
      return majorityElementHelper (nums, 0, nums.size()-1, found);
    }
};

