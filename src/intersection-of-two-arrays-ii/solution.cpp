class Solution {
  public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      vector<int> retval;
      if (!nums1.size() || !nums2.size()) return retval;
      sort(nums1.begin(), nums1.end());
      sort(nums2.begin(), nums2.end());
      int idx1 = 0, idx2 = 0;
      int end1 = nums1.size(), end2 = nums2.size();
      while (idx1 < end1 && idx2 < end2) {
        if (nums1[idx1] > nums2[idx2]) idx2++;
        else if (nums1[idx1] < nums2[idx2]) idx1++;
        else {
          retval.push_back(nums1[idx1]);
          int count1 = 0, count2 = 0;
          int currVal = nums1[idx1];
          while (idx1 < end1 && nums1[idx1] == currVal) {
            idx1++;
            count1++;
          }
          while (idx2 < end2 && nums2[idx2] == currVal) {
            idx2++;
            count2++;
          }
          count1 = min(count1, count2);
          for (int i = 1; i < count1; i++) {
            retval.push_back(currVal);
          }
        }
      }
      return retval;
    }
};
