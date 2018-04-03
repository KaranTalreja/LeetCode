class Solution {
  public:
    bool isHappy(int n) {
      unordered_set<int> hash;
      while(1) {
        int newN = 0;
        if (hash.find(n) != hash.end()) return false;
        else hash.insert(n);
        if (n == 1) return true;
        while (n) {
          newN += ((n % 10) * (n % 10));
          n /= 10;
        }
        n = newN;
      }
    }
};
