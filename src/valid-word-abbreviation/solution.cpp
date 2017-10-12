/*
Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".

Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

Example 1:
Given s = "internationalization", abbr = "i12iz4n":

Return true.
Example 2:
Given s = "apple", abbr = "a2e":

Return false.
*/
class Solution {
  public:
    bool validWordAbbreviation(string word, string abbr) {
      int size = word.size();
      if (!size) return false;
      int abbrSize = abbr.size();
      if (!abbrSize) return false;
      int j = 0;
      int i = 0, w = 0;
      for (i = 0, w = 0; i < abbrSize && w < size; i++, w++) {
        if (abbr[i] > '0' && abbr[i] <= '9') {
          j = i;
          while (abbr[i] >= '0' && abbr[i] <= '9') {
            i++;
          }
          w += stoi(abbr.substr(j, i-j));
          i--;
          w--;
        } else {
          if (word[w] != abbr[i]) return false;
        }
      }
      if (w != size || i != abbrSize) return false;
      return true;
    }
};
