class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      size_t size = nums.size();
      vector<int> count (size);
      vector<int> retval;
      for (int i = 0 ; i < size; i++) count[nums[i]-1]++; 
      for (int i = 0 ; i < size; i++) if(count[i] == 0) retval.push_back(i+1);

      return retval;
    }
};
