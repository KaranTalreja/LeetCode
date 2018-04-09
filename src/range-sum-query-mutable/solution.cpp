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
class NumArray {
  public:
    int N;
    int size;
    vector<int> tree;
    void helperInit(vector<int>& nums, int start, int end, int parent) {
      if (end - start == 1) {
        tree[parent] = nums[start];
        return;
      }
      int mid = start + (end-start)/2;
      helperInit(nums, start, mid, 2*parent+1);
      helperInit(nums, mid, end, 2*parent+2);
      tree[parent] = tree[2*parent+1] + tree[2*parent+2];
    }

    int helperSum(int i, int j, int start, int end, int parent) {
      if (j < start || i > end-1) return 0;
      if (i <= start && j >= end-1) return tree[parent];
      int mid = start + (end-start)/2;
      return helperSum(i, j, start, mid, 2*parent+1) + helperSum(i, j, mid, end, 2*parent+2);
    }

    void helperUpdate(int i, int start, int end, int parent, int val) {
      if (end - start == 1) {
        tree[parent] = val;
        return;
      }
      int mid = start + (end - start)/2;
      if (i < mid) helperUpdate(i, start, mid, 2*parent+1, val);
      else helperUpdate(i, mid, end, 2*parent+2, val);
      tree[parent] = tree[2*parent+1] + tree[2*parent+2];
    }

    NumArray(vector<int> nums) : N(nums.size()), size(2*pow(2, ceil(log2(N)))-1), tree(N > 0 ? size : 1, 0) {
      if (N > 0)  helperInit(nums, 0, N, 0);
      // for (auto x : tree) cout << x << " ";
      // cout << endl;
    }

    void update(int i, int val) {
      helperUpdate(i, 0, N, 0, val);
      // for (auto x : tree) cout << x << " ";
      // cout << endl;
    }

    int sumRange(int i, int j) {
      return helperSum(i, j, 0, N, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
