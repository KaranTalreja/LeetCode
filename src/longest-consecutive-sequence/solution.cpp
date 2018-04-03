class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> hash;
      for (auto i : nums) {
        hash.insert(i);
      }
      int size = nums.size();
      if (!size) return size;
      int retval = 1;
      for (int i = 0; i < size; i++) {
        int curr = nums[i];
        if (hash.find(curr) == hash.end()) continue;
        hash.erase(curr);
        int next = curr+1;
        while (hash.find(next) != hash.end()) hash.erase(next++);
        int prev = curr-1;
        while (hash.find(prev) != hash.end()) hash.erase(prev--);
        if (retval < next -prev -1) retval = next-prev-1;
      }
      return retval;
    }
};
