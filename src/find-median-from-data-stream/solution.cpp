class MedianFinder {
  public:
    class comp {
      public:
        bool operator() (const int& a, const int& b) const {
          if (a > b) return true;
          return false;
        }
    };

    /** initialize your data structure here. */
    priority_queue<int, vector<int>, comp> minQ;
    priority_queue<int> maxQ;
    double currMedian;
    MedianFinder() {
      currMedian = 0;
    }

    void addNum(int num) {
      if (num < currMedian) maxQ.push(num);
      else minQ.push(num);
      while (abs(minQ.size() - maxQ.size()) > 1) {
        if (minQ.size() > maxQ.size()) {
          maxQ.push(minQ.top());
          minQ.pop();
        } else {
          minQ.push(maxQ.top());
          maxQ.pop();
        }
      }
      if (minQ.size() == maxQ.size()) currMedian = (maxQ.top() + minQ.top()) / 2.0;
      else if (minQ.size() < maxQ.size()) currMedian = maxQ.top();
      else currMedian = minQ.top();
    }

    double findMedian() {
      return currMedian;
    }
};
