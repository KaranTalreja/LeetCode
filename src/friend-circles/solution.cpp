class Solution {
  public:
    int findCircleNum(vector<vector<int>>& M) {
      int N = M.size();
      if (!N) return 0;
      int retval = 0;
      vector<bool> visited(N, false);
      queue<int> Q;
      for (int i = 0; i < N; i++) {
        if (visited[i] == true) continue;
        Q.push(i);
        visited[i] = true;
        while (!Q.empty()) {
          int curr = Q.front();
          // cout << curr << " ";
          Q.pop();
          for (int j = 0; j < N; j++) {
            if (M[curr][j] == true && visited[j] == false) {
              Q.push(j);
              visited[j] = true;
            }
          }
        }
        // cout << endl;
        retval++;
      }
      return retval;
    }
};
