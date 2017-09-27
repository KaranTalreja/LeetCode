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
    static bool comp(const Interval& a, const Interval& b) {
      if (a.start < b.start) return true;
      return false;
    }

    bool overlaps(Interval& a, Interval& b) {
      if (b.start <= a.end) return true;
      return false;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
      int size = intervals.size();
      if (!size) return intervals;
      vector<Interval> retval;
      sort(intervals.begin(),intervals.end(), comp);
      int j = 0;
      for (int i = 1; i < intervals.size(); i++) {
        if (overlaps(intervals[j], intervals[i])) {
          intervals[j].end = max(intervals[i].end, intervals[j].end);
        } else {
          retval.push_back(intervals[j]);
          j = i;
        }
      }
      retval.push_back(intervals[j]);
      return retval;
    }
};
