class Solution {
  public:

    void helper (int n, int nOpenParen, int nCloseParen, int& maxPairs, string& currStr, vector<string>& retval) {
      if (n == 0) { retval.push_back(currStr); }
      else {
        if (nOpenParen < maxPairs) {
          currStr += "(";
          helper(n-1, nOpenParen+1, nCloseParen, maxPairs, currStr, retval);
          currStr.pop_back();
        }
        if (nOpenParen > nCloseParen) {
          currStr += ")";
          helper(n-1, nOpenParen, nCloseParen+1, maxPairs, currStr, retval);
          currStr.pop_back();
        } 
      }
    }

    vector<string> generateParenthesis(int n) {
      vector<string> retval;
      if (!n) return retval;
      string currStr = "";
      helper(2*n, 0, 0, n, currStr, retval);
      return retval;
    }
};
