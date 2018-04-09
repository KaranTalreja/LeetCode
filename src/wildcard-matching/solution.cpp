class Solution {
  public:
    bool isMatch(string s, string p) {
      int N = s.size();
      int M = p.size();
      vector<vector<bool>> DP(N+1, vector<bool>(M+1, false));
      DP[0][0] = true;
      for (int j = 0; j < M; j++) {
        if (p[j] == '*') DP[0][j+1] = DP[0][j]; 
      }

      for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
          if (s[i-1] == p[j-1] || p[j-1] == '?') DP[i][j] = DP[i-1][j-1];
          else if (p[j-1] == '*') {
            for (int k = i; k >= 0; k--) {
              if (DP[k][j-1] == true) {
                DP[i][j] = true;
                break; 
              }
            }
          }
        }
      }
      // for (auto r : DP) {
      //     for (auto c : r) {
      //         cout << c << " ";
      //     }
      //     cout << endl;
      // }
      return DP[N][M];
    }
};
