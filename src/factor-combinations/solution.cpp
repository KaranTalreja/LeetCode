/*Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note: 
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Examples: 
input: 1
output: 
[]
input: 37
output: 
[]
input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]*/

class Solution {
  public:
    void helper(int n, vector<int>& currBreak, vector<vector<int>>& retval, int& N, int lastFactor) {
      if (n == 1) retval.push_back(currBreak);
      for (int i = lastFactor; i <= n && i < N; i++) {
        if (n % i) continue;
        currBreak.push_back(i);
        helper(n/i, currBreak, retval, N, i);
        currBreak.pop_back();
      }
    }

    vector<vector<int>> getFactors(int n) {
      vector<vector<int>> retval;
      if (n <= 1) return retval;
      vector<int> currBreak;
      helper(n,currBreak,retval,n,2);
      return retval;
    }
};
