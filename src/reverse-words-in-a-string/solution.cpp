#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Solution {
  public:
    void reverseWords(string &s) {
      string copy(s);
      s.clear();
      const char* c_str = strdup(copy.c_str());
      while (*c_str == ' ') c_str++;
      char* word = (char*)strrchr(c_str, ' ');
      while (NULL != word) {
        if (*(word + 1) != '\0') {
          s += strdup(word+1) + string(" ");
        }
        *word = '\0';
        word = (char*)strrchr(c_str, ' ');
      }
      if (strlen(c_str) != 0) s += strdup(c_str);
    }
};

int main() {
  string s = "    the sky ";
  Solution a;
  a.reverseWords(s);
  cout << s <<"EE"<< endl;
}
