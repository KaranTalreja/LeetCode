/*
Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:

[1,2,3]
[4,5,6,7]
[8,9]
It should return [1,4,8,2,5,9,3,6,7].
*/
class ZigzagIterator {
  public:
    vector<vector<int>::iterator> itrs;
    vector<vector<int>::iterator> endItrs;
    int currIdx;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
      itrs.push_back(v1.begin());
      endItrs.push_back(v1.end());
      itrs.push_back(v2.begin());
      endItrs.push_back(v2.end());
      currIdx=0;
    }

    int next() {
      while(itrs[currIdx] == endItrs[currIdx]) currIdx = (currIdx+1)%itrs.size();
      int retval = *itrs[currIdx];
      if (itrs[currIdx] != endItrs[currIdx]) itrs[currIdx]++;
      currIdx = (currIdx+1)%itrs.size();
      return retval;
    }

    bool hasNext() {
      int N = itrs.size();
      int tempIdx = currIdx;
      while (N >= 0) {
        if (itrs[tempIdx] != endItrs[tempIdx]) return true;
        N--;
        tempIdx = (tempIdx+1) % itrs.size();
      }
      return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
