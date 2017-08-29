class Solution {
  public:
    int countPrimes(int n) {
      if (n <= 2) return 0;
      vector<int> hash(n,1);
      hash[0] = 0;
      for (int i = 2; i < n; i++) {
        if (hash[i-1] == 0) continue;
        int mult=2;
        while (i*mult < n) {
          hash[i*mult-1] = 0;
          mult++;
        }
      }
      int retval = 0;
      for (int i=0; i < n-1; i++) retval+=hash[i];
      return retval;
    }
};
