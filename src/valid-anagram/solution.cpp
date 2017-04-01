class Solution {
  public:
    bool isAnagram(string s, string t) {
      if (s.empty() && t.empty()) return true;
      const char* sc = s.c_str();
      const char* tc = t.c_str();
      if (s.length() != t.length()) return false;
      int length = s.length();
      typedef map<char,int> T;
      T hash;
      for (int i =0; i < length; i++) {
        T::iterator itr = hash.find(sc[i]);
        if (itr != hash.end()) hash[sc[i]] += 1;
        else hash[sc[i]] = 1;
      }
      for (int i =0; i < length; i++) {
        T::iterator itr = hash.find(tc[i]);
        if (itr != hash.end()) {
          hash[tc[i]] -= 1;
          if (hash[tc[i]] < 0) return false;
        }
        else return false;
      }
      T::iterator itr = hash.begin();
      for (; itr!= hash.end(); itr++) {
        if (itr->second > 0) return false;
      }
      return true;
    }
};
