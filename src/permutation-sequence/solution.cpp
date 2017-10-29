/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/
class Solution {
  public:
    void reverse(char& a, char& b) {
      char temp = a;
      a = b;
      b = temp;
    }
    void reverse(string& s, int i , int j) {
      while (i < j) {
        swap(s[i], s[j]);
        i++;
        j--;
      }
    }
    void getNextPermutation(string& s) {
      int size = s.size();
      int i = size-1;
      for (; i > 0; i--) {
        if (s[i-1] < s[i]) break;
      }
      int min = INT_MAX;
      int idx = i;
      for (int j = i; j < size; j++) {
        if (s[j] > s[i-1] && s[j] <= min) { min = s[j]; idx = j; }
      }
      swap(s[i-1], s[idx]);
      reverse(s, i, size-1);
      return;
    }

    string getPermutation(int n, int k) {
      string s;
      for (int i = 1; i <=n; i++) s.push_back(char('0'+i));
      for (int i = 1; i < k; i++) {

        getNextPermutation(s);
      }
      return s;
    }
};
