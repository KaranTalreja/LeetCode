/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
class Solution {
  public:
    string convert(string s, int numRows) {
      if (numRows <= 0) return "";
      int size = s.size();
      if (!size) return "";
      vector<vector<char>> rows (numRows, vector<char>());
      int start = 0;
      bool increasing = true;
      for (int i = 0; i < size; i++) {
        rows[start].push_back(s[i]);
        if (increasing && start < numRows-1) start++;
        else if (!increasing && start > 0) start--;
        if (start == 0 || start == numRows-1) increasing = !increasing;
      }
      string retval;
      for (auto x : rows) {
        for (auto y : x) {
          retval += y;
        }
      }
      return retval;
    }
};
