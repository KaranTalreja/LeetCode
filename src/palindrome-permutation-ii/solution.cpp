/*
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].
*/
class Solution {
  public:

    void DFS(string& currString, int startIdx, int endIdx, vector<int>& hash, vector<string>& retval) {
      if (startIdx >= endIdx) {
        retval.push_back(currString);
        return;
      }
      for (int i = 0; i < hash.size(); i++) {
        if (hash[i]) {
          hash[i] -= 2;
          currString[startIdx] = i;
          currString[endIdx] = i;
          DFS(currString, startIdx+1, endIdx-1, hash, retval);
          hash[i] += 2;
        }
      }
    }

    vector<string> generatePalindromes(string s) {
      vector<string> retval;
      int size = s.size();
      if (!size) return retval;
      vector<int> hash (255,0);
      for (auto c: s) hash[c]++;
      bool foundOdd = false;
      char oddChar = 0;
      for (int c = 0; c< hash.size(); c++) {
        if (hash[c] % 2) {
          if (foundOdd == true) return retval;
          foundOdd = true;
          oddChar = c;
        }
      }
      string currString(s);
      if (foundOdd == true) {
        currString[size/2] = oddChar;
        hash[oddChar]--;
      }
      DFS(currString, 0, size-1, hash, retval);
      return retval;
    }
};
