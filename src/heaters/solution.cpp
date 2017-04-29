class Solution {
  public:
    int findHeater(int house, vector<int>& heaters) {
      int start = 0;
      int end = heaters.size();
      while (end - start > 1) {
        int mid = start + (end - start)/2;
        if (heaters[mid] <= house)  start = mid;
        else end = mid;
      }
      int retval = abs(heaters[start] - house);
      if (end < heaters.size()) {
        if (retval > abs(heaters[end] - house)) retval = abs(heaters[end] - house);
      }
      return retval;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
      int retval = 0;
      if (!heaters.size()) return INT_MAX;
      sort(houses.begin(), houses.end());
      sort(heaters.begin(), heaters.end());
      int numHouses = houses.size();
      for (int h = 0; h < numHouses; h++) {
        int closestHeater = findHeater(houses[h], heaters);
        if (retval < closestHeater) retval = closestHeater;
      }
      return retval;
    }
};
