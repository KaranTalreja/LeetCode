class Solution {
  public:

    bool DFS (unordered_map<int, unordered_set<int>> & graph, int start, vector<int>& visitedBy) {
      for (auto e: graph[start]) {
        int visit =  visitedBy[e];
        if (visit == -1) {
          visitedBy[e] = start;
          if(!DFS(graph, e, visitedBy)) return false;
        } else if (visitedBy[start] != e) return false;
      }
      return true;
    }

    bool validTree(int n, vector<pair<int, int>>& edges) {
      vector<int> visitedBy(n, -1);
      unordered_map<int, unordered_set<int>> graph;
      for(auto e : edges) {
        if (e.first == e.second) return false;
        graph[e.first].insert(e.second);
        graph[e.second].insert(e.first);
      }
      visitedBy[0] = 0;
      bool rc = DFS(graph, 0, visitedBy);
      if (rc == true) {
        for (auto v : visitedBy) {
          if (v == -1) return false;
        }
      }
      return rc;
    }
};

