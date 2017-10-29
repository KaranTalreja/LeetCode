/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
/*
What i have tried to do is find the first place in the array from right which is smaller than it's previous element.

Now let that be the MSB of the number that we need to increment lexicographically. Since we increase this by smallest possible
number we increment the entire number. Also if the MSB turns out to be the actual MSB then we just reverse the array.

Now given an MSB we find the smallest possible greater element of it on the right. since this will increase the MSB by the least.
After finding this element we swap it with current MSB and reverse the array after MSB till end.Now reversing an array which
has all elements in decreasing order would make it in increasing order, thus smallest possible value for LSB array. To mantain the
property that the LSB array is decreasing we swap the MSB with closest larger smallest value in case of duplicates. Assume we have
 [2,3,3,3]. Now if we swap to [3,3,3,2] and reverse it we get [3,2,3,3] which is incorrect. We should swap like this [3,2,3,3] and reverse
to correct answer [3,3,3,2].
*/
class Solution {
  public:
    void swap(int& a, int& b) {
      int temp = a;
      a = b;
      b = temp;
    }
    void reverse(vector<int>& nums, int i, int j) {
      while (i < j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
      }
    }
    void nextPermutation(vector<int>& nums) {
      int size = nums.size();
      if (!size) return;
      int i = size -1;
      for (i = size-1; i > 0; i--) {
        if(nums[i-1] < nums[i]) break;
      }
      if (i == 0) {
        reverse(nums, 0, size-1);
        return;
      }
      int min = INT_MAX;
      int idx = i;
      for (int j = i; j < size; j++) {
        if (nums[j] > nums[i-1] && nums[j] <= min) { min = nums[j]; idx = j; }
      }
      swap(nums[i-1], nums[idx]);
      reverse(nums, i, size-1);
      return;
    }
};
