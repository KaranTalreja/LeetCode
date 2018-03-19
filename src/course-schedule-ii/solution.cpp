class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
      vector<unordered_set<int>> outgoingEdges(numCourses);
      set <int> visited;
      map<int,int> incomingEdges;
      for (auto e : prerequisites) {
        outgoingEdges[e.second].insert(e.first);
        auto x = incomingEdges.find(e.first);
        if (x == incomingEdges.end()) incomingEdges[e.first] = 1;
        else x->second++;
        x = incomingEdges.find(e.second);
        if (x == incomingEdges.end()) incomingEdges[e.second] = 0;
      }
      vector<int> topoSort;
      for (int i = 0; i < numCourses; i++) {
        for (auto s : incomingEdges) {
          if (s.second == 0) {
            topoSort.push_back(s.first);
            visited.insert(s.first);
            for (auto o : outgoingEdges[s.first]) {
              incomingEdges[o]--;
            }
            auto itr = incomingEdges.find(s.first);
            incomingEdges.erase(itr);
            break;
          }
        }
      }
      if (!incomingEdges.empty()) return vector<int>();
      for (int i = 0; i < numCourses; i++) {
        if (visited.end() == visited.find(i)) topoSort.push_back(i);
      }
      return topoSort;
    }
};
