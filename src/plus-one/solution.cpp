class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
      int length = digits.size();
      int carry = 1;
      while (carry) {
        digits[length-1] += 1;
        if (digits[length-1] > 9) {
          digits[length-1] %= 10;
          carry = 1;
          length--;
          if (length == 0) {
            digits.insert(digits.begin(), 1);
            break;
          }
        }
        else carry = 0;
      }
      return digits;
    }
};
