/*
Given a set of words (without duplicates), find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y
Note:
There are at least 1 and at most 1000 words.
All words will have the exact same length.
Word length is at least 1 and at most 5.
Each word contains only lowercase English alphabet a-z.
Example 1:

Input:
["area","lead","wall","lady","ball"]

Output:
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
Example 2:

Input:
["abat","baba","atan","atal"]

Output:
[
  [ "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
*/

class Solution {
  public:
    class Trie {
      public:
        vector<Trie*> children;
        vector<int> dictIndices;
        Trie() {
          children = vector<Trie*>(26,NULL);
        }
        void insertHelper(Trie* root, string::iterator begin, string::iterator end, int dictIdx) {
          if (begin == end) return;
          int idx = *begin-'a';
          if (root->children[idx] == NULL) root->children[idx] = new Trie();
          root->dictIndices.push_back(dictIdx);
          insertHelper(root->children[idx],begin+1,end, dictIdx);
        }
        void insert(string s, int idx) {
          if (s.empty()) return;
          insertHelper(this, s.begin(), s.end(), idx);
        }
        void lookupHelper(Trie* root, string::iterator begin, string::iterator end, vector<int>& retval) {
          if (begin == end) {
            retval = root->dictIndices;
            return;
          }
          int idx = *begin - 'a';
          if (root->children[idx] == NULL) return;
          lookupHelper(root->children[idx], begin+1, end, retval);
        }
        vector<int> lookup (string prefix) {
          vector<int> retval;
          if (prefix.empty()) return retval;
          lookupHelper(this, prefix.begin(), prefix.end(), retval);
          return retval;
        } 
    };
    vector<int> getOptions(string prefix, Trie*& root) {
      vector<int> retval = root->lookup(prefix);
      return retval;
    } 

    void helper(vector<string>& words, int row, int L, vector<string>& currPath, vector<vector<string>>& retval, Trie*& root) {
      if (row >= L) {retval.push_back(currPath); return;}
      int size = currPath.size();
      string prefix;
      for (int i = 0; i < row; i++) {
        prefix += currPath[i][row];
      }
      vector<int> options(getOptions(prefix, root));
      for (int i = 0; i < options.size(); i++) {
        currPath.push_back(words[options[i]]);
        helper(words,row+1, L, currPath, retval, root);
        currPath.pop_back();
      }
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
      int N = words.size();
      vector<vector<string>> retval;
      if (!N) return retval;
      int L = words[0].size();
      vector<string> currPath;
      Trie* root = new Trie();
      for (int i = 0; i < N; i++) { root->insert(words[i],i); }
      for (int i = 0; i < N; i++) {
        currPath.push_back(words[i]);
        helper(words, 1, L, currPath, retval, root);
        currPath.pop_back();
      }
      return retval;
    }
};
