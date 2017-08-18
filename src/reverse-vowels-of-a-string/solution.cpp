class Solution {
  public:
    string reverseVowels(string s) {
      vector<int> idx;
      string vowels;
      for (int i = 0; i < s.size(); i++) {
        switch(s[i]) {
          case 'A':
          case 'a':
          case 'E':
          case 'e':
          case 'I':
          case 'i':
          case 'O':
          case 'o':
          case 'U':
          case 'u':
            {
              vowels += s[i];
              idx.push_back(i);
            }
            break;
          default:
            break;
        }
      }
      int start = 0;
      int end = vowels.size()-1;
      while (start < end) {
        char temp = vowels[start];
        vowels[start] = vowels[end];
        vowels[end] = temp;
        start++;
        end--;
      }
      for (int i = 0; i < idx.size(); i++) {
        s[idx[i]] = vowels[i];
      }
      return s;   
    }
};
// Alternative solution
class Solution {
  public:
    bool isVowel (char c) {
      switch (c) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
          return true;
        default:
          return false;
      }
    }
    string reverseVowels(string s) {
      int f=0, e=s.size()-1;
      while (f < e) {
        while (!isVowel(s[f])) f++;
        while (!isVowel(s[e])) e--;
        if (f >= e) break;
        char temp = s[f];
        s[f] = s[e];
        s[e] = temp;
        e--;
        f++;
      }
      return s;
    }
};
