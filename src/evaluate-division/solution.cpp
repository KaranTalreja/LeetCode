class Solution {
  public:
    void DFS(map<string, map<string, double>>& graph, string source, string dest, double& retval, double rc, map<string,bool>& visited, bool& found) {
      if (source == dest) {
        retval = rc;
        found = true;
        return;
      }
      visited[source] = true;
      for (auto itr = graph[source].begin(); itr != graph[source].end(); itr++) {
        if (visited[itr->first] == false) {
          DFS(graph, itr->first, dest, retval, rc*itr->second, visited, found);
        }
      }
      visited[source] = false;
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
      int size = equations.size();
      int queriesSize = queries.size();
      vector<double> retval (queriesSize, -1.0);
      if (!size) return retval;
      map<string, map<string, double>> grph;
      map<string, bool> visited;
      for (int i = 0; i < size; i++) {
        string first = equations[i].first;
        string second = equations[i].second;
        double value = values[i];
        auto itr = grph.find(first);
        map<string, double> tmp;
        tmp[second] = value;
        if (itr == grph.end()) {
          grph[first] = tmp;
          visited[first] = false;
        } else {
          grph[first][second] = value;
        }
        itr = grph.find(second);
        map<string, double> tmpRev;
        tmpRev[first] = 1.0/value;
        if (itr == grph.end()) {
          grph[second] = tmpRev;
          visited[second] = false;
        } else {
          grph[second][first] = 1.0/value;
        }
      }

      for (int i = 0; i < queriesSize; i++) {
        string first = queries[i].first;
        string second = queries[i].second;
        if (grph.find(first) == grph.end() || grph.find(second) == grph.end()) continue;
        double rc = 1.0;
        bool found = false;
        DFS(grph, first, second, rc, 1.0, visited, found);
        if (found) retval[i] = rc;
      }
      return retval;
    }
};

