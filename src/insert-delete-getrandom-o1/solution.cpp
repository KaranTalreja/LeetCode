class RandomizedSet {
  public:
    map<int, int> hash;
    vector<int> data;
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    void debug() {
      for (int i = 0; i < data.size(); i++) {
        cout << data[i] <<",";
      }
      cout << endl;
    }
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
      map<int, int>::iterator itr= hash.find(val);
      if (itr == hash.end()) {
        data.push_back(val);
        hash.insert(pair<int,int>(val, data.size()-1));
        //debug();
        return true;
      }
      return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
      map<int, int>::iterator itr= hash.find(val);
      if (itr == hash.end()) return false;
      int idx = itr->second;
      hash.erase(itr);
      int temp = data[idx];
      data[idx] = data.back();
      data[data.size()-1] = temp;
      data.pop_back();
      itr = hash.find(data[idx]);
      itr->second = idx;
      //debug();
      return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
      if (!data.size()) return -1;
      //debug();
      int idx = rand() % data.size();
      return data[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
