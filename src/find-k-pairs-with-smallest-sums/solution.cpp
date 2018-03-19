class Solution {
  public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      int N1 = nums1.size();
      int N2 = nums2.size();
      vector<pair<int,int>> retval;
      if (!N1 || !N2) return retval;
      vector<int> indices(N1, 0);
      pair<int,int> temp;
      for (int k1 = 0; k1 < k && k1 < N1*N2; k1++) {   
        int min = INT_MAX;
        int idx = -1;
        for (int i = 0; i < N1; i++) {
          if (indices[i] < N2 && nums1[i] + nums2[indices[i]] <= min) {
            min = nums1[i] + nums2[indices[i]];
            idx = i;
            temp.first = nums1[i];
            temp.second = nums2[indices[i]];
          }
        }
        indices[idx]++;
        retval.push_back(temp);
      }
      return retval;
    }
};
