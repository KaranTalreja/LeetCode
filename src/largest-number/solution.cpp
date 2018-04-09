class Solution {
  public:
    static bool comp(string& a, string& b) {
      if (strcmp(string(a+b).c_str(), string(b+a).c_str()) > 0) return true;
      return false;
    }

    string largestNumber(vector<int>& nums) {
      int N = nums.size();
      if(!N) return "";
      vector<string> numsStr(N);
      for (int i = 0; i < N; i++) numsStr[i] = to_string(nums[i]);
      sort(numsStr.begin(), numsStr.end(), comp);
      string retval;
      for (auto s : numsStr) retval += s;
      int size = retval.size();
      int i = 0;
      for (i = 0; i < size-1; i++) {
        if (retval[i] != '0') 
          break;
      }
      return retval.substr(i,size-i);
    }
};
