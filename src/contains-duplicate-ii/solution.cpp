class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      size_t size = nums.size();
      if (size <= 1) return false;
      if (k <= 0) return false;
      typedef typename std::map<int, int> T;
      T m;
      for (int i = 0; i< size; i++) {
        pair<typename T::iterator, bool> rc = m.insert(std::pair<int,int>(nums[i],i));
        if (rc.second == false) {
          if (abs(i - rc.first->second) <= k) return true;
          rc.first->second = i;
        }
      }
      return false;
    }
};
