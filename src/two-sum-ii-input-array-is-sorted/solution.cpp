class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      size_t size = numbers.size();
      int start = 0, end = size -1;
      vector<int> retval;
      while (end - start >= 1) {
        int curr_sum = numbers[start] + numbers[end];
        if (target == curr_sum) {
          retval.push_back(start+1);
          retval.push_back(end+1);
          break;
        } else if (target > curr_sum) start++;
        else end--;
      }
      return retval;
    }
};
