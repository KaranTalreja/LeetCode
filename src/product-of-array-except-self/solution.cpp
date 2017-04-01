class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      size_t size = nums.size();
      int fwd_product = 1, bwd_product = 1;
      vector<int> retval(size,1);
      retval[0] = 1;
      retval[size-1] = 1;
      for (int i=0, j = size-1 ; i < size && j >= 0; i++, j--) {
        retval[i] *= fwd_product;
        retval[j] *= bwd_product;
        bwd_product *= nums[j];
        fwd_product *= nums[i];
      }
      return retval;
    }
};
