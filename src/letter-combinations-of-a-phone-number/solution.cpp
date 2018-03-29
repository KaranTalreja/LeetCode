class Solution {
  public:
    void DFS(string& digits, int start, string& curr, vector<string>& retval) {
      if (start == digits.size()) {
        retval.push_back(curr);
        return;
      }
      static vector<string> options = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      for (auto o : options[digits[start] - '0']) {
        char bk = curr[start];
        curr[start] = o;
        DFS(digits, start+1, curr, retval);
        curr[start] = bk;
      }
    }

    vector<string> letterCombinations(string digits) {
      string curr(digits);
      vector<string> retval;
      int size = digits.size();
      if (!size) return retval;
      DFS(digits, 0, curr, retval);
      return retval;
    }
};

class Solution {
  public:
    string mapping(char digit) {
      switch(digit) {
        case '2': return "abc";
        case '3': return "def";
        case '4': return "ghi";
        case '5': return "jkl";
        case '6': return "mno";
        case '7': return "pqrs";
        case '8': return "tuv";
        case '9': return "wxyz";
        default: return "";        
      }
    }

    void helper (string& digits, int index, int& size, string& currStr, vector<string>& retval) {
      if (index == size) retval.push_back(currStr);
      else {
        string choices = mapping(digits[index]);
        for (int i = 0; i < choices.size(); i++) {
          currStr += choices[i];
          helper(digits, index+1, size, currStr, retval);
          currStr.pop_back();
        }
      }
    }

    vector<string> letterCombinations(string digits) {
      vector<string> retval;
      int size = digits.size();
      if (!size) return retval;
      const char* temp = strchr(digits.c_str(), '0');
      if (NULL != temp) return retval;
      temp = strchr(digits.c_str(), '1');
      if (NULL != temp) return retval;
      string currStr = "";
      helper(digits, 0, size, currStr, retval);
      return retval;
    }
};
