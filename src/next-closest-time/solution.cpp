class Solution {
  public:
    int timeDiff (int& mins, string& newT) {
      int a = stoi(newT.substr(0,2));
      int b = stoi(newT.substr(3,2));
      if (a > 23) return INT_MAX;
      if (b > 59) return INT_MAX;
      int minsB = a * 60 + b;
      if (minsB < mins) return 1440 - mins + minsB;
      else if (minsB == mins) return INT_MAX;
      else return minsB - mins;
    }

    void helper(string& orig, int start, int& diff, string& curr, string& retval, int& mins) {
      if (start == orig.size()) {
        int rc = timeDiff(mins, curr);
        if (rc < diff) {
          retval = curr;
          diff = rc;
        }
        return;
      }
      if (curr[start] == ':') {
        helper(orig, start+1, diff, curr, retval, mins); 
        return;
      }
      for (int i = 0; i < orig.size(); i++) {
        if (orig[i] == ':') continue;
        char bk = curr[start];
        curr[start] = orig[i];
        helper(orig, start+1, diff, curr, retval, mins);
        curr[start] = bk;
      }
    }

    string nextClosestTime(string time) {
      string retval = time;
      int diff = INT_MAX;
      string curr = time;
      int mins = stoi(time.substr(0,2)) * 60 +  stoi(time.substr(3,2));
      helper(time, 0, diff, curr, retval, mins);
      return retval;
    }
};
