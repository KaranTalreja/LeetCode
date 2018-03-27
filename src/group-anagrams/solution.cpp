class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      map<string, vector<string>> hash;
      for (auto x : strs) {
        string temp(x);
        sort(temp.begin(), temp.end());
        if (hash.find(temp) == hash.end()) hash[temp] = vector<string>();
        hash[temp].push_back(x);
      }
      vector<vector<string>> retval;
      for (auto i : hash) {
        retval.push_back(i.second);
      }
      return retval;
    }
};
