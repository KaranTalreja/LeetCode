/*
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

Note:
The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
*/
class Codec {
  public:
    string encode(vector<string>& strs) {
      string retval;
      for (int i = 0; i < strs.size(); i++) {
        retval += to_string(strs[i].size()) + "," + strs[i];
      }
      return retval;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
      vector<string> retval;
      int j = 0;
      int numChar = 0;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
          numChar = stoi(s.substr(j,i-j));
          retval.push_back(s.substr(i+1, numChar));
          i += numChar;
          j = i+1;
        } 
      }
      return retval;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
