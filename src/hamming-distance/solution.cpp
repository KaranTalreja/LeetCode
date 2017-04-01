class Solution {
  public:
    int hammingDistance(int x, int y) {
      int z = x ^ y;
      int distance = 0;
      while (z) {
        distance += (z&0x01);
        z = z >> 1;
      }
      return distance;
    }
};
