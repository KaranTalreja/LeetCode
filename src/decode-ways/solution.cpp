class Solution {
  public:
    bool isValid (string s) {
      if (s[0] == '0') return false;
      int i = stoi(s);
      if (i >= 1 && i <= 26) return true;
      return false;
    }

    int numDecodings(string s) {
      int size = s.size();
      if (!size) return 0;
      vector<int> DP(size, 0);
      vector<bool> valid(size, false);
      if (isValid(s.substr(size-1, 1))) {
        valid[size-1] = true;
        DP [size-1] = 1;
      }
      for (int i = size-2; i >=0; i--) {
        int count = 0;
        if (isValid(s.substr(i,1)) && valid[i+1] == true) {
          count += DP[i+1];
          valid[i] = true;
        }
        if (i+2 <= size && isValid(s.substr(i,2))) {
          if (i+2 == size) {
            count += 1;
            valid[i] = true;                    
          } else if (valid[i+2] == true) {
            count += DP[i+2];
            valid[i] = true;
          }

        }
        DP[i] = count;
      }
      return DP[0];
    }
};
