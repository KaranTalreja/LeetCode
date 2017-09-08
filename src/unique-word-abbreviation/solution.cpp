/*
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example: 
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> 
false

isUnique("cart") -> 
true

isUnique("cane") -> 
false

isUnique("make") -> 
true

*/
class ValidWordAbbr {
  public:
    map <string, vector<string>> dictMap;
    string abbreviate(string s) {
      if (s.size() <= 2) return s;
      string retval;
      retval += s[0];
      retval += to_string(s.size()-2);
      retval += s[s.size()-1];
      return retval;
    }

    ValidWordAbbr(vector<string> dictionary) {
      map<string, vector<string>>::iterator itr;
      set<string> uniqueStrings;
      for (int i = 0; i < dictionary.size(); i++) {
        if (uniqueStrings.find(dictionary[i]) != uniqueStrings.end()) continue;
        uniqueStrings.insert(dictionary[i]);
        string key = abbreviate(dictionary[i]);
        itr = dictMap.find(key);
        if (itr != dictMap.end()) {
          itr->second.push_back(dictionary[i]);
        } else {
          dictMap[key] = vector<string>(1,dictionary[i]);
        }
      }
    }

    bool isUnique(string word) {
      string abbrev = abbreviate(word);
      map<string, vector<string>>::iterator itr = dictMap.find(abbrev);
      if (itr == dictMap.end()) return true;
      if (itr->second.size() >= 2) return false;
      if (itr->second[0] == word) return true;
      return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
