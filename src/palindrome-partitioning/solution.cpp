class Solution {
  public:

    void DFS(vector<vector<bool>>& DP, string& s, int& size, vector<vector<string>>& retval, vector<string>& currPath, int idx) {
      if (idx >= size) {
        retval.push_back(currPath);
        return;
      }
      for (int i = idx; i < size; i++) {
        if (DP[idx][i] == true) {
          currPath.push_back(s.substr(idx, i-idx+1));
          DFS(DP, s, size, retval, currPath, i+1);
          currPath.pop_back();
        }
      }
    }

    vector<vector<string>> partition(string s) {
      int size = s.size();
      vector<vector<string>> retval;
      vector<vector<bool>> DP(size, vector<bool>(size, false));
      for (int i = 0; i < size; i++) {
        DP[i][i] = true;
      }
      for (int L = 2; L <= size; L++) {
        for (int i = 0,j = L-1; j < size; i++, j++) {
          if (L == 2) {
            if (s[i] == s[j]) DP[i][j] = true;
          } else {
            if (DP[i+1][j-1] == true && s[i] == s[j]) DP[i][j] = true;
          }
        }
      }
      vector<string> currPath;
      DFS(DP, s, size, retval, currPath, 0);
      return retval;
    }
};
