/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

class MovingAverage {
  public:
    /** Initialize your data structure here. */
    queue<int> m_window;
    double m_oldAvg;
    int m_size;
    MovingAverage(int size) {
      m_oldAvg = 0;
      m_size = size;
    }
    double next(int val) {
      int size = m_window.size();
      double retval;
      if (size < m_size) {
        retval = (m_oldAvg * size + val)/(size+1);
        m_window.push(val);
      } else {
        retval = ((m_oldAvg*m_size - m_window.front()) + val) / m_size;
        m_window.pop();
        m_window.push(val);
      }
      m_oldAvg = retval;
      return retval;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
