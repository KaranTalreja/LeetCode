class Solution {
  public:
    void parseComplex(string& c, int& a, int& b) {
      int size = c.size();
      int i = 0;
      for (i; i < size; i++) {
        if (c[i] == '+') {
          a = stoi(c.substr(0,i));
          break;
        }
      }
      int j = i+1;
      for (i; i < size; i++) {
        if (c[i] == 'i') {
          b = stoi(c.substr(j,i-j));
        }
      }
    }

    string complexNumberMultiply(string c1, string c2) {
      int a, b;
      parseComplex(c1, a, b);
      int c, d;
      parseComplex(c2, c, d);
      // (a + ib)*(c + id) = (ac -bd) + (ad + bc)i
      string retval;
      retval += to_string(a*c - b*d);
      retval += '+';
      retval += to_string(a*d + b*c);
      retval += 'i';
      return retval;
    }
};
