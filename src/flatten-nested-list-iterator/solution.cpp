/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
  public:
    typedef typename vector<NestedInteger> :: iterator myItr;
    vector<myItr> stackBegin;
    vector<myItr> stackEnd;
    NestedIterator(vector<NestedInteger> &nestedList) {
      myItr curr = nestedList.begin();
      myItr end = nestedList.end();
      stackBegin.push_back(curr);
      stackEnd.push_back(end);
    }

    int next() {
      myItr curr = stackBegin.back();
      while (!curr->isInteger()) {
        stackBegin.push_back(curr->getList().begin());
        stackEnd.push_back(curr->getList().end());
        curr = stackBegin.back();
      }
      int retval = curr->getInteger();
      while (++stackBegin.back() == stackEnd.back()) {
        stackBegin.pop_back();
        stackEnd.pop_back();
        if (stackBegin.empty()) break;
      }
      return retval;
    }

    bool hasNext() {
      if (stackBegin.empty()) return false;
      while(stackBegin.back() == stackEnd.back() || stackBegin.back()->isInteger() == false) {
        if (stackBegin.back() == stackEnd.back()) {
          stackBegin.pop_back();
          stackEnd.pop_back();
          if (stackBegin.empty()) return false;
          stackBegin.back()++;
        } else if (stackBegin.back()->isInteger() == false) {
          myItr temp = stackBegin.back();
          stackBegin.push_back(temp->getList().begin());
          stackEnd.push_back(temp->getList().end());
        }
      }
      return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
