class Solution {
  public:

    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
      if (a.first < b.first) return true;
      return false;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> counts;
      for (auto n : nums) {
        auto rc = counts.find(n);
        if (rc != counts.end()) rc->second++;
        else counts[n] = 1;
      }
      priority_queue<pair<int,int>, vector<pair<int,int>>, Solution> Q;
      pair<int, int> temp;
      for (auto c : counts) {
        temp.first = c.second;
        temp.second = c.first;
        Q.push(temp);
      }
      vector<int> retval;
      for (int i = 0; i < k; i++) {
        retval.push_back(Q.top().second);
        Q.pop();
      }
      return retval;
    }
};
