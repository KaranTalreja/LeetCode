class Solution {
  public:
    int firstUniqChar(string s) {
      map<char, pair<int, int>> hash; 
      int retval = -1;
      int size = s.size();
      if (!size) return retval;
      for (int i = 0; i < size; i++) {
        map<char, pair<int,int>>::iterator itr = hash.find(s[i]);
        if (itr == hash.end()) hash.insert(pair<char, pair<int,int>> (s[i], pair<int,int>(i, 1)));
        else itr->second.second++;
      }
      map<char, pair<int,int>>::iterator itr = hash.begin();
      int min = INT_MAX;
      for (itr; itr!= hash.end(); itr++) {
        if(itr->second.second == 1 && itr->second.first < min) min = itr->second.first;
      }
      retval = min;
      if (retval == INT_MAX) retval = -1;
      return retval;
    }
};
class Solution {
  public:
    int firstUniqChar(string s) {
      vector<int> hash(26,-1);
      int size = s.size();
      for (int i = 0; i < size ; i++) {
        if (hash[s[i] - 'a'] == -1) hash[s[i] - 'a'] = i;
        else if (hash[s[i] - 'a'] >= 0) hash[s[i] - 'a'] = -2;
      }
      int min = INT_MAX;
      for (auto x : hash) {
        if (x != -1 && x != -2 && min > x) min = x;
      }
      if (min == INT_MAX) return -1;
      return min;
    }
};
