/*
Write a function to find the longest common prefix string amongst an array of strings.
*/
class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
      string retval;
      int size = strs.size();
      if (!size) return retval;
      if (size == 1) return strs[0];
      for (int l = 0; l < strs[0].size(); l++) {
        char common = strs[0][l];
        bool isCommon = true;
        for (int i = 0; i < size; i++) {
          if (l >= strs[i].size()) return retval;
          if (strs[i][l] != common) {isCommon = false; break;} 
        }
        if (isCommon) retval+=common;
        else return retval;
      }
      return retval;
    }
};

class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
      int len = 0;
      int size = strs.size();
      if (!size) return "";
      vector<string::iterator> heads(size);
      vector<string::iterator> ends(size);
      for (int i = 0; i < size; i++) {
        heads[i] = strs[i].begin();
        ends[i] = strs[i].end();
      }
      int retval = -1;
      bool mismatch = false;
      while (!mismatch) {
        retval++;
        char c;
        for (int i = 0; i < size && mismatch == false;  i++) {
          if (heads[i] == ends[i]) {mismatch=true; break;}
          if (i == 0) c = *heads[i];
          if (*heads[i] != c) {mismatch=true; break;}
          heads[i]++;
        }
      }
      return strs[0].substr(0,retval);
    }
};
