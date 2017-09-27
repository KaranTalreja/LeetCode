/*
Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/
class Solution {
  public:
    void helper(string& word, int start, string& currStr, vector<string>& options, vector<string>& retval) {
      if (start >= word.size()) {
        retval.push_back(currStr);
        return;
      }
      currStr += word[start];
      helper(word, start+1, currStr, options, retval);
      currStr.pop_back();
      for (int i = 0; i < options.size(); i++) {
        string bk = currStr;
        currStr += options[i];
        if (start+stoi(options[i]) <= word.size()) {
          if (start+stoi(options[i]) != word.size()) currStr += word[start+stoi(options[i])]; 
          helper(word, start+1+stoi(options[i]), currStr, options, retval);
          if (start+stoi(options[i]) != word.size())currStr.pop_back();
        }
        currStr = bk;
      }
    }

    vector<string> generateAbbreviations(string word) {
      int size = word.size();
      vector<string> retval;
      if(!size) {
        retval.push_back("");
        return retval;
      }
      string currStr;
      vector<string> options;
      for (int i = 1; i <= size; i++) options.push_back(to_string(i));
      helper(word, 0, currStr, options, retval);
      return retval;
    }
};
