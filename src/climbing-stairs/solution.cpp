class Solution {
  public:
    int climbStairs(int n) {
      vector<int> opt(n+1,0);
      opt[0] = 0;
      opt[1] = 1;
      opt[2] = 2;
      for (int i = 3; i < n+1; i++) {
    // Number of ways to climb i-1 steps + number of ways to
    // climb i-2 steps
        opt[i] = opt[i-1] + opt[i-2];
      }
      return opt[n];
    }
};
