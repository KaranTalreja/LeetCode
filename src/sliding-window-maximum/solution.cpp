class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      std::deque<int> dq;
      vector<int> retval;
      int N = nums.size();
      if (!N) return retval;
      int i = 0;
      for (i = 0; i < k; i++) {
        while (!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();
        dq.push_back(i);
      }
      for (; i < N; i++) {
        retval.push_back(nums[dq.front()]);
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();

        while (!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();

        dq.push_back(i);
      }
      retval.push_back(nums[dq.front()]);
      return retval;
    }
};
