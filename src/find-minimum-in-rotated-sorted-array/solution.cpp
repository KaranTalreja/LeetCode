class Solution {
  public:
    int findMin(vector<int>& nums) {
      int start = 0; int end = nums.size()-1;
      while (nums[start] > nums[end]) {
        int mid = (start+end)/2;
        if (nums[mid] < nums[start]) end = mid;
        else start = mid+1;
      }
      return nums[start]; 
    }
};
