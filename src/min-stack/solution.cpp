class MinStack {
  public:
    /** initialize your data structure here. */
    vector<int> val;
    vector<int> minVal;
    MinStack() {

    }

    void push(int x) {
      val.push_back(x);
      if (minVal.empty()) minVal.push_back(x);
      else {
        if (minVal.back() < x) minVal.push_back(minVal.back());
        else minVal.push_back(x);
      }
    }

    void pop() {
      val.pop_back();
      minVal.pop_back();
    }

    int top() {
      return val.back();
    }

    int getMin() {
      return minVal.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
