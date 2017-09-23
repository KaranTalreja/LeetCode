/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/

class Solution {
  public:
    bool check(char a, char b) {
      if (a == '1' && b == '1') return true;
      if (a == '0' && b == '0') return true;
      if (a == '6' && b == '9') return true;
      if (a == '9' && b == '6') return true;
      if (a == '8' && b == '8') return true;
      return false;
    }

    bool isStrobogrammatic(string num) {
      int size = num.size();
      if (size < 1) return true;
      int i = 0;
      int j = size-1;
      while (i <= j) {
        if (!check(num[i], num[j])) return false;
        i++;
        j--;
      }
      return true;
    }
};
