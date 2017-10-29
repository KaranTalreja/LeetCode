/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
  public:
    void DFS(int i, int& n, int& k, vector<int>& currPath, vector<vector<int>>& retval) {
      if (currPath.size() == k) {
        retval.push_back(currPath);
        return;
      }
      if (i > n) return;
      currPath.push_back(i);
      DFS(i+1, n, k, currPath, retval);
      currPath.pop_back();
      DFS(i+1, n, k, currPath, retval);
    }
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> retval;
      vector<int> currPath;
      DFS(1, n, k, currPath, retval);
      return retval;
    }
};
