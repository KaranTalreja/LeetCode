class Solution {
  public:
    void helper(string& s, int idx, int& size, string& currStr, int currEdit, int& minEdit, vector<char>& stack, set<string>& retval) {
        if (currEdit > minEdit) return;
        if (idx == size) {
        if (stack.empty()) {
          if (currEdit < minEdit) {
            minEdit = currEdit;
            retval.clear();
            retval.insert(currStr);
          } else if (minEdit == currEdit) retval.insert(currStr);
        }
        return;
      }

      helper(s, idx+1, size, currStr, currEdit+1, minEdit, stack, retval);
      if (s[idx] == '(') stack.push_back(s[idx]);
      else if (s[idx] == ')') {
        if (stack.empty()) return;
        if (stack.back() == '(') stack.pop_back();
        else return;
      }
      currStr.push_back(s[idx]);
      helper(s, idx+1, size, currStr, currEdit, minEdit, stack, retval);
      if (s[idx] == '(') stack.pop_back();
      else if (s[idx] == ')') stack.push_back('(');
      currStr.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
      int minEdit = INT_MAX;
      int currEdit = 0;
      vector<string> retval;
      set<string> setStrings;
      vector<char> stack;
      string currStr;
      int size = s.size();
      if (!size) {
          retval.push_back("");
          return retval;
      }
      currStr.reserve(size);
      helper(s, 0, size, currStr, currEdit, minEdit, stack, setStrings);
      if (setStrings.empty()) retval.push_back("");
      else {
          for (auto x : setStrings) retval.push_back(x);
      }
      return retval;
    }
};
