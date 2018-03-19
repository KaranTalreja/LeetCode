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

// Alternative solution : Recursive
class SolutionRecur {
  public:
    vector<int> helper(vector<int>& digits, int index, size_t& size, int& carry) {
      if (index < size) helper(digits, index+1, size, carry);
      else { carry = 1; return digits;}
      digits[index] += carry;
      if (digits[index] >= 10) {
        carry = digits[index]/10;
        digits[index] %= 10;
      } else carry = 0;
      return digits;
    }
    vector<int> plusOne(vector<int>& digits) {
      int carry = 0;
      int idx = 0;
      size_t size = digits.size();
      digits = helper(digits, idx, size, carry);
      if (carry == 1) digits.insert(digits.begin(),1);
      return digits;
    }
};

class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
      int size = digits.size();
      int carry = 0;
      int temp;
      for (int i = size-1; i >= 0; i--) {
        if (i == size-1)    temp = digits[i] + 1;
        else    temp = digits[i] + carry;
        digits[i] = temp % 10;
        carry = temp / 10;
      }
      if (carry == 1) digits.insert(digits.begin(), 1);
      return digits;
    }
};
