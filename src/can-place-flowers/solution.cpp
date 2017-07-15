class Solution {
  public:
    bool tryPlacingUtil(vector<int>& flowerbed, int index, int n) {
      //cout << "Checking for "<<index<<" placing "<<n << " flowers" << endl;
      if (index >= flowerbed.size() && n > 0) return false;
      if (n == 0) return true;
      if (flowerbed[index] == 1) return tryPlacingUtil(flowerbed, index+2, n);
      else {
        bool retval = false;
        if ((index-1 < 0 || flowerbed[index-1] == 0) && (index+1 >= flowerbed.size() || flowerbed[index+1] == 0)) {
          flowerbed[index] = 1;
          retval = tryPlacingUtil(flowerbed, index+2, n-1);
          flowerbed[index] = 0;
          return retval;
        } else retval = tryPlacingUtil(flowerbed, index+1, n);
        return retval;
      }
    }

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int size = flowerbed.size();
      if (n > size/2+1) return false;
      return tryPlacingUtil(flowerbed, 0, n);
    }
};
