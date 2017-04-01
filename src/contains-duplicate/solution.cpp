class Solution {
  public:
#include <unordered_set>
    bool containsDuplicate(vector<int>& nums) {
      unordered_set<int> S;
      size_t size = nums.size();
      if(size <= 1) return false;
      for (int i = 0; i < size; i++) {
        if (S.insert(nums[i]).second == false) return true;
      }
      return false;
    }
};
