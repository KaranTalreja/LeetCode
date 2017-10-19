/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/

class NumArray {
  public:
    vector<int> bitIndexTree;
    vector<int> data;

    void updateTree(int idx, int val) {
      int size = bitIndexTree.size();
      for (int i = idx; i < size; i += i&(-i)) {
        bitIndexTree[i] += val;   
      }
    }

    int queryTree(int idx) {
      int size = bitIndexTree.size();
      int retval = 0;
      for (int i = idx; i > 0; i -= i&(-i)) {
        retval += bitIndexTree[i];
      }
      return retval;
    } 

    NumArray(vector<int> nums) : data(nums), bitIndexTree(vector<int>(nums.size()+1, 0)) {
      int size = nums.size();
      for (int i = 0; i < size; i++) {
        updateTree(i+1, nums[i]);
      }
    }

    void update(int i, int val) {
      if (i < 0 || i >= data.size()) return;
      int diff = val - data[i];
      data[i] = val;
      updateTree(i+1, diff);
    }

    int sumRange(int i, int j) {
      if (i < 0 || j >= data.size()) return -1;
      return queryTree(j+1) - queryTree(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
