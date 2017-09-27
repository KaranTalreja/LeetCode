/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].
*/
class Solution {
  public:
    void helper(string& str, int start, int end, vector<string>& retval) {
      if (start > end) {retval.push_back(str); return;}
      if (start == end) {
        string options = "018";
        for (int i = 0; i < options.size(); i++) {
          if (start == 0 && options[i] == '0' &&  str.size() != 1) continue;
          char s = str[start];
          str[start] = options[i];
          helper(str, start+1, end-1, retval);
          str[start] = s;
        }
      } else {
        vector<string> options = {"00", "11", "69", "88", "96"};
        for (int i = 0; i < options.size(); i++) {
          if (start == 0 && options[i][0] == '0') continue;
          char s = str[start];
          char e = str[end];
          str[start] = options[i][0];
          str[end] = options[i][1];
          helper(str, start+1, end-1, retval);
          str[start] = s;
          str[end] = e;
        }
      }
    }

    vector<string> findStrobogrammatic(int n) {
      vector<string> retval;
      if (!n) {
        retval.push_back("");
        return retval;
      }
      string str(n, '0');
      helper(str, 0, n-1, retval);
      return retval;
    }
};
