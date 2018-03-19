/*
The trick to using only one hash for characters from both s and t is as follows.

The invariant is since we are adding and subtracting the count for each character
from s exactly once, the final count should be equal to what it was initialized with.

Now we initialize it with the counts from t. When we start adding, the counts of only
characters in t will go back to positive. When they do we can check for 0 and increase
the counter. This counter tracks the number of characters from t in the current window.
*/

class Solution {
  public:
    string minWindow(string s, string t) {
      vector<int> hash(256, 0);
      for (auto c : t) hash[c]++;
      int counter = t.size();
      int size = s.size();
      int j = 0;
      int min = INT_MAX;
      string retval;
      for (int i = 0; i < size; i++) {
        if (hash[s[i]] > 0) counter--;
        hash[s[i]]--;
        while(counter == 0) {
          if (min > i - j + 1) {
            min = i -j + 1; 
            retval = s.substr(j, i-j+1);
          }
          if (hash[s[j]] == 0) counter++;
          hash[s[j]]++;
          j++;
        }
      }
      return retval;
    }
};
