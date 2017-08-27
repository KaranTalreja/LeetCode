class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k) {
      int length = nums.size();
      int idx = rand() % length;
      vector<int> smaller;
      vector<int> equal;
      vector<int> larger;
      for (int i = 0; i < length; i++) {
        if (nums[i] < nums[idx]) smaller.push_back(nums[i]);
        else if (nums[i] > nums[idx]) larger.push_back(nums[i]);
        else equal.push_back(nums[i]);
      }
      if (larger.size() == k-1) return nums[idx];
      else if (larger.size() > k-1) return findKthLargest(larger, k);
      else {
        if (larger.size() + equal.size() > k-1) return nums[idx];
        return findKthLargest(smaller, k - equal.size() - larger.size());
      }
    }
};
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class SolutionInPlace {
public:
    // Selects target'th smallest
    int partition (vector<int> & nums, int start, int end) {
        if (start >= end) return start;
        int pivot = end;
        int i = start-1;
        for (int j = start; j < pivot; j++) {
            if (nums[j] <= nums[pivot]) {
                i++;
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        int temp = nums[pivot];
        nums[pivot] = nums[i+1];
        nums[i+1] = temp;
        return i+1;
    }
    int quickSelect(vector<int>& nums, int start, int end, int target) {
        int pos = partition(nums, start, end);
        if (target-1 == pos-start) return nums[pos];
        else if (target < pos-start+1) return quickSelect(nums, start, pos-1, target);
        else return quickSelect(nums,pos+1, end, target-pos +start-1);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, nums.size() - k + 1);
    }
};

int main() {
  vector<int> nums = {5,4,3,2,1};
  int target = 5;
  SolutionInPlace ans;
  cout << ans.findKthLargest(nums, target) << endl;
  return 0;
}
