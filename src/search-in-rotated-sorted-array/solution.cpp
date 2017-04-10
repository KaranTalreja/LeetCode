#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;


class Solution {
  public:
    int search(vector<int>& nums, int target) {
      int start = 0; int end = nums.size()-1;
      if (end < 0) return -1;
      while (end - start > 1) {
        int mid = (start+end)/2;
        if (nums[mid] == target) return mid;
        if (nums[start] < nums[end]) {
          if (target < nums[mid]) end = mid;
          else start = mid+1;
        } else {
          if (target < nums[mid]) {
            if (nums[mid] < nums[start]) end = mid;
            else if (target <= nums[end]) start = mid+1;
            else end = mid;
          } else {
            if (target > nums[start]) {
              if (nums[start] < nums[mid]) start = mid + 1;
              else end = mid; 
            } else if (target <= nums[end]) start = mid+1;
            else end = mid;
          }
        }
      }
      if (nums[start] == target) return start;
      if (nums[end] == target) return end;
      return -1;
    }
};

class Solution2 {
  public:
    int bin_search(vector<int>& nums, int target, int start, int end) {
      while (start < end) {
        int mid = (start + end)/2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) start = mid+1;
        else end = mid;
      }
      if (nums[end] == target) return end;
      return -1;
    }

    int search(vector<int>& nums, int target) {
      int size = nums.size();
      if (!size) return -1;
      int start = 0;
      int end = size - 1;
      int mid;
      while (nums[start] > nums[end]) {
        mid = (start + end)/2;
        if (nums[mid] < nums[start]) end = mid;
        else start = mid+1;
      }
      if (start == 0) {
        return bin_search(nums, target, 0, end);
      } else {
        if (target >= nums[0]) return bin_search(nums, target, 0, start-1);
        else return bin_search(nums, target, start, size-1);
      }
    }
};

int main() {
  vector<int> a = {1,2,3,4};
  Solution2 obj;
  cout << obj.search(a, -1) << endl;
  cout << obj.search(a, 0) << endl;
  cout << obj.search(a, 1) << endl;
  cout << obj.search(a, 2) << endl;
  cout << obj.search(a, 3) << endl;
  cout << obj.search(a, 4) << endl;
  cout << obj.search(a, 5) << endl;
  cout << obj.search(a, 6) << endl;
  cout << obj.search(a, 7) << endl;
  cout << obj.search(a, 8) << endl;
}
