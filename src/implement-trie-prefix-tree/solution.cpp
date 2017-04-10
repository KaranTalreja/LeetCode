#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Trie {
  public:
    vector<Trie*> children;
    bool wordEnds;
    /** Initialize your data structure here. */
    Trie() : children(vector<Trie*>(26,NULL)) {
      wordEnds = false;
    }

    void insertHelper (Trie* root, string::iterator begin, string::iterator end) {
      if (begin == end) {
        root->wordEnds = true;
        return;
      }
      int idx = (int)(*begin) - (int)('a');
      if (NULL != root->children[idx])  insertHelper(root->children[idx], begin+1, end);
      else {
        root->children[idx] = new Trie();
        insertHelper(root->children[idx], begin+1, end);
      }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
      if (word.empty()) return;
      insertHelper(this, word.begin(), word.end());
    }

    bool searchHelper(Trie* root, string::iterator begin, string::iterator end) {
      if (begin == end) return root->wordEnds;
      int idx = (int)(*begin) - (int)('a');
      if (NULL == root->children[idx]) return false;
      return searchHelper(root->children[idx], begin+1, end);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
      if (word.empty()) return false;
      return searchHelper(this, word.begin(), word.end());
    }

    bool startsWithHelper(Trie* root, string::iterator begin, string::iterator end) {
      if (begin == end) return true;
      int idx = (int)(*begin) - (int)('a');
      if (NULL == root->children[idx]) return false;
      return startsWithHelper(root->children[idx], begin+1, end);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      if (prefix.empty()) return false;
      return startsWithHelper(this, prefix.begin(), prefix.end());
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main() {
  Trie* obj = new Trie();
  string word = "sead";
  string prefix = "se";
  obj->insert(word);
  // bool param_2 = obj->search("s");
  bool param_3 = obj->startsWith(prefix);
  cout << param_3 << endl;
}
