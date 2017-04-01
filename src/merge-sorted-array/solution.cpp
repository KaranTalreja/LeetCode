class Solution {
  public:
    void reverse(vector<int>& nums, int start, int end) {
      while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
      }
    }

    void rotate(vector<int>& nums, int k) {
      reverse(nums, 0, nums.size()-1);
      reverse(nums, 0, k-1);
      reverse(nums, k, nums.size()-1);
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int begin = m;
      int i1 = 0, i2 = 0;
      for (i1 = 0, i2 = 0; i1 < m && i2 < n ; ) {
        if (nums1[i1] <= nums2[i2]) nums1[begin++] = nums1[i1++];
        else nums1[begin++] = nums2[i2++];
        if (begin > n+m-1) begin = 0;
      }
      if (begin > n+m-1) begin = 0;
      while (i1 < m) {
        nums1[begin++] = nums1[i1++];
        if (begin > n+m-1) begin = 0;
      }
      while (i2 < n) {
        nums1[begin++] = nums2[i2++];
        if (begin > n+m-1) begin = 0;
      }
      rotate(nums1, n);
    }
};
