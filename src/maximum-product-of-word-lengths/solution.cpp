class Solution {
  public:
    int maxProduct(vector<string>& words) {
      map<int,int> hash;
      for (auto x : words) {
        int val = 0;
        for (auto c : x) {
          val |= (0x1 << (c - 'a'));
        }
        if (hash.find(val) == hash.end()) hash[val] = x.size();
        else hash[val] = hash[val] < x.size() ? x.size() : hash[val];
      }
      int max = 0;
      for (auto h1 : hash) {
        for (auto h2 : hash) {
          if ((h1.first & h2.first) == 0 && max < h1.second * h2.second) {
            max = h1.second * h2.second;
          } 
        }
      }
      return max;
    }
};
