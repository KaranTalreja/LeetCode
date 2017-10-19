/*
Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

Given:

    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]

Output:

    [-2, 0, 3, 5, 3]
Explanation:

Initial state:
[ 0, 0, 0, 0, 0 ]

After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]

After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]

After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]
Credits:
Special thanks to @vinod23 for adding this problem and creating all test cases.
*/

class Solution {
  public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
      vector<int> retval;
      if (length <= 0) return retval;
      retval = vector<int>(length,0);
      for (auto x : updates) {
        if (x[0] >= 0) retval[x[0]] += x[2];
        if (x[1]+1 < length) retval[x[1]+1] += -x[2];
      }
      int cum_sum = 0;
      for (int i =0 ; i < length; i++) {
        cum_sum += retval[i];
        retval[i] = cum_sum;
      }
      return retval;
    }
};
