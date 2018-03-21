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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
      int start = 0;
      int end = intervals.size();
      int mid;
      if (!end) {
        intervals.push_back(newInterval);
        return intervals;
      }
      if (newInterval.end < intervals[0].start) {
        intervals.insert(intervals.begin(), newInterval);
        return intervals;
      } else if (newInterval.start > intervals.back().end) {
        intervals.push_back(newInterval);
        return intervals;
      }
      while (end - start > 1) {
        mid = start + (end - start)/2;
        if (intervals[mid].start <= newInterval.start) start = mid;
        else end = mid;
      }
      vector<Interval> stack;
      stack.push_back(intervals[start]);
      end = intervals.size();
      if (newInterval.start <= stack.back().end) stack.back().end = max(newInterval.end, stack.back().end);
      else stack.push_back(newInterval);
      if (start == 0 && newInterval.start < stack.back().start) stack.back().start = newInterval.start; 
      int i;
      for (int i = start+1; i < end; i++) {
        if (intervals[i].start <= stack.back().end) stack.back().end = max(intervals[i].end, stack.back().end);
        else stack.push_back(intervals[i]);
      }
      intervals.erase(intervals.begin()+start, intervals.end());
      intervals.insert(intervals.end(), stack.begin(), stack.end());
      return intervals;
    }
};
