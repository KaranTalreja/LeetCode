/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.
*/
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

    bool operator() (const pair<int,int>& a, const pair<int,int>& b) const {
      if (a.first > b.first) return true;
      return false;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
      int numMeetings = 0;
      pair<int,int> temp;
      priority_queue<pair<int,int>, vector<pair<int,int>>, Solution> myQ;
      unordered_map<int,int> timeNumMeetingMap;
      for (auto i : intervals) {
        if (timeNumMeetingMap.find(i.start) == timeNumMeetingMap.end()) timeNumMeetingMap[i.start] = 1;
        else timeNumMeetingMap[i.start]++;
        if (timeNumMeetingMap.find(i.end) == timeNumMeetingMap.end()) timeNumMeetingMap[i.end] = -1;
        else timeNumMeetingMap[i.end]--;
      }
      for (auto m : timeNumMeetingMap ) {
        myQ.push(m);
      }
      while (!myQ.empty()) {
        numMeetings += myQ.top().second;
        myQ.pop();
        if (numMeetings > 1) return false;
      }
      return true;
    }
};
