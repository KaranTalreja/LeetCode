class NumArray {
  public:
    int N, size;
    vector<int> tree;
    void helperInit(vector<int>& nums, int start, int end, int parent) {
      if (end - start == 1){
        tree[parent] = nums[start];
        return;
      }
      int mid = start + (end - start)/2;
      helperInit(nums, start, mid, 2*parent+1);
      helperInit(nums, mid, end, 2*parent+2);
      tree[parent] = tree[2*parent+1] + tree[2*parent+2];
    }

    int helperRange (int i, int j, int start, int end, int parent) {
      if (i > end-1 || j < start) return 0;
      if (i <= start && j >= end-1) return tree[parent];
      int mid = start + (end - start)/2;
      return helperRange(i, j, start, mid, 2*parent+1) + helperRange(i, j, mid, end, 2*parent+2);
    }

    NumArray(vector<int> nums) : N(nums.size()), size(2*pow(2, ceil(log2(N)))-1), tree(N > 0 ? size : 1, 0) {
      if (N > 0) helperInit(nums, 0, N, 0);
    }

    int sumRange(int i, int j) {
      return helperRange(i, j, 0, N, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
