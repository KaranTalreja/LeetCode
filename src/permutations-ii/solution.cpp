/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
class Solution {
  public:

    void DFS(vector<int>& nums, int startIdx, int &size, vector<vector<int>>& retval, map<int,int>& counts) {
      if (startIdx == size) {
        retval.push_back(nums);
        return;
      }
      for (map<int,int>::iterator itr = counts.begin(); itr != counts.end(); itr++) {
        if (itr->second) {
          nums[startIdx] = itr->first;
          itr->second -= 1;
          DFS(nums, startIdx+1, size, retval, counts);
          itr->second += 1;
        }
      }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> retval;
      int size = nums.size();
      if (!size) return retval;
      map<int, int> counts;
      auto itr = counts.begin();
      for (auto n : nums) {
        itr = counts.find(n);
        if (itr != counts.end()) counts[n]++;
        else counts[n] = 1;
      }
      DFS(nums,0,size,retval, counts);
      return retval;
    }
};
