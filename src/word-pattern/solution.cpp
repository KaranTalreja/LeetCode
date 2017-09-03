class Solution {
  public:
    string getWord (int& i, string& str) {
      int j;
      if (i >= str.size()) return "";
      for (j = i; j < str.size(); j++) {
        if (str[j] == ' ') break;
      }
      string retval = str.substr(i, j-i);
      i = j+1;
      return retval;
    }

    bool wordPattern(string pattern, string str) {
      vector<string> hash(26);
      map<string, char> wordDict;
      map<string, char>::iterator itr;
      int j = 0;
      if (str.empty() || pattern.empty()) return false;
      for (int i = 0; i < pattern.size(); i++) {
        if (j >= str.size()) return false;
        string temp = getWord(j, str);
        itr = wordDict.find(temp);
        if (itr == wordDict.end()) wordDict[temp] = pattern[i];
        else if (itr->second != pattern[i]) return false;
        //cout << temp << endl;
        if (hash[pattern[i]-'a'].empty()) hash[pattern[i]-'a'] = temp;
        else if (temp.compare(hash[pattern[i]-'a'])) return false;
      }
      return (j >= str.size()) ? true : false;
    }
};
