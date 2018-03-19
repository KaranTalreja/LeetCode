class Solution {
  public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
      if (!prerequisites.size()) return true;
      map<int, int> incomingEdges;
      map<int, vector<int>> outgoingEdges;
      for (auto x : prerequisites) {
        auto rc = incomingEdges.find(x.second);
        if (rc != incomingEdges.end()) rc->second++;
        else incomingEdges[x.second] = 1;
        rc = incomingEdges.find(x.first);
        if (rc == incomingEdges.end()) incomingEdges[x.first] = 0;
        outgoingEdges[x.first].push_back(x.second);
      }
      // for (auto x : incomingEdges) cout << x.first << " " << x.second << endl;
      // for (auto x : outgoingEdges) {
      //     cout << x.first << ":";
      //     for (auto y : x.second) cout << y << " ";
      //     cout << endl;
      // }
      vector<int> topoSort;
      for (int i = 0; i < numCourses; i++) {
        for (auto e : incomingEdges) {
          if (e.second == 0) {
            topoSort.push_back(e.first);
            for (auto o : outgoingEdges[e.first]) {
              incomingEdges[o] -= 1;
            }
            auto rc = incomingEdges.find(e.first);
            incomingEdges.erase(rc);
            break;
          }
        }
      }
      // for (auto x : topoSort) cout << x << endl;
      if (topoSort.size() == numCourses) return true;
      return false;
    }
};
