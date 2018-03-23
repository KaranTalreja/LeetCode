class Solution {
  public:
    int kEmptySlots(vector<int>& flowers, int k) {
      int size = flowers.size();
      vector<int> bloomed(size+1, 0);
      for (int i = 0; i < size; i++) {
        bloomed[flowers[i]] = 1;
        if (flowers[i]-k-1 >= 1 && bloomed[flowers[i]-k-1] == 1) {
          bool found = true;
          for (int j = flowers[i]-k; j >= 1 && j < flowers[i]; j++) {
            if (bloomed[j] == 1) {
              found = false;
              break;
            }
          }
          if (found == true) return i+1;
        }
        if (flowers[i]+k+1 <= size && bloomed[flowers[i]+k+1] == 1) {
          bool found = true;
          for (int j = flowers[i]+k; j > flowers[i]; j--) {
            if (bloomed[j] == 1) {
              found = false;
              break;
            }
          }
          if (found == true) return i+1;
        }
      }
      return -1;
    }
};
