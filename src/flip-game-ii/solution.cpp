/*
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.
*/
class Solution {
  public:
    bool helper(string s, map<string, bool>& hash) {
      static int k = 2;
      if (hash.find(s) != hash.end()) return hash[s];
      bool retval = false;
      class scratch {
        string* str;
        int i;
        public:
        scratch(string* s, int i) : str(s), i(i){
          str->operator[](i) = '-';
          str->operator[](i+1) = '-';
        }
        ~scratch() {
          str->operator[](i) = '+';
          str->operator[](i+1) = '+';
        }
      };
      for (int i = 0; i < s.size() - k + 1; i++) {
        if ("++" == s.substr(i,2)) {
          scratch obj(&s, i);
          if (!helper(s, hash)) {
            retval = true;
            break;
          }

        }
      }
      hash[s] = retval;
      return retval;
    }

    bool canWin(string s) {
      int size = s.size();
      if (!size) return false;
      map<string, bool> hash;
      return helper(s, hash);
    }
};
