class Solution {
  public:
    static bool comp(pair<int, int> a, pair<int, int> b) {
      return a.first > b.first ? true : false;
    }

    string frequencySort(string s) {
      vector<pair<int, int>> hash(255,pair<int,int>(0,-1));
      int size = s.size();
      if (!size) return s;
      for (int i = 0; i < size; i++) {
        hash[s[i]].first++;
        hash[s[i]].second = i;
      }
      sort(hash.begin(), hash.end(), comp);
      int k = 0;
      string retval(s);
      for (int i = 0; i < 255; i++) {
        for (int j = hash[i].first; j > 0; j--) {
          retval[k++] = s[hash[i].second];
        }
      }
      return retval;
    }
};
