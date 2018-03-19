class Solution {
  public:

    bool check(string* smaller, string* larger, int s, int l, int depth) {
      if (depth > 1) return false;
      int m = smaller->size();
      int n = larger->size();
      for (int i = s, j = l; i < m && l < n; i++, j++) {
        if ((*smaller)[i] != (*larger)[j]) return check(smaller, larger, i, j+1, depth+1);
      }
      return true;
    }

    bool isOneEditDistance(string s, string t) {
      int m = s.size();
      int n = t.size();
      if (abs(m-n) > 1) return false;
      string* smaller = &s, *larger = &t;
      bool rc = true;
      if (m > n) {
        string* temp = smaller;
        smaller = larger;
        larger = temp;
      }
      if (m != n) {
        return check(smaller, larger, 0, 0, 0);
      } else {
        int c = 0;
        for (int i = 0; i < m; i++) {
          if (s[i] != t[i]) c++;
          if (c == 2) return false;
        }
        if (c == 1) return true;
        return false;
      }
    }
};
