class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k) {
      int length = nums.size();
      int idx = rand() % length;
      vector<int> smaller;
      vector<int> equal;
      vector<int> larger;
      for (int i = 0; i < length; i++) {
        if (nums[i] < nums[idx]) smaller.push_back(nums[i]);
        else if (nums[i] > nums[idx]) larger.push_back(nums[i]);
        else equal.push_back(nums[i]);
      }
      if (larger.size() == k-1) return nums[idx];
      else if (larger.size() > k-1) return findKthLargest(larger, k);
      else {
        if (larger.size() + equal.size() > k-1) return nums[idx];
        return findKthLargest(smaller, k - equal.size() - larger.size());
      }
    }
};
