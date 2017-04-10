class Solution {
  public:
    bool isValid(string s) {
      vector<char> stack;
      int length = s.size();
      for (int i = 0; i < length; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') stack.push_back(s[i]);
        else {
          if (stack.empty()) return false;
          if (s[i] == ')' && stack.back() != '(') return false;
          else if (s[i] == '}' && stack.back() != '{') return false;
          else if (s[i] == ']' && stack.back() != '[') return false;
          else stack.pop_back();
        }
      }
      return stack.empty();
    }
};
