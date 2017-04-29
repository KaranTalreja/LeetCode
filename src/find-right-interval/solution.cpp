/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
  public:
    static bool cmpI(pair<int, Interval> A, pair<int, Interval> B) {
      return A.second.start < B.second.start;
    }

    int getRightInterval(Interval& target, vector<pair<int, Interval>>& intervalWithIdx) {
      int end = target.end;
      int l = 0;
      int r = intervalWithIdx.size();
      while (r - l > 1) {
        int m = l + (r-l)/2;
        if (intervalWithIdx[m].second.start >= end) r = m;
        else l = m;
      }
      if (r != intervalWithIdx.size()) return intervalWithIdx[r].first;
      return -1;
    }

    vector<int> findRightInterval(vector<Interval>& intervals) {
      vector<int> retval;
      if (!intervals.size()) return retval; 
      vector<pair<int, Interval>> intervalWithIdx;
      int size = intervals.size();
      for (int i = 0; i < size; i++) {
        intervalWithIdx.push_back(pair<int, Interval>(i, intervals[i]));
      }
      sort(intervalWithIdx.begin(), intervalWithIdx.end(), cmpI);
      for (int i = 0; i < size; i++) {
        retval.push_back(getRightInterval(intervals[i], intervalWithIdx));
      }
      return retval;
    }
};
