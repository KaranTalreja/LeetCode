class Solution {
  public:
    void insertDeq (deque<vector<int>>& m_stack, vector<int>& building) {
      int l = 0;
      int r = m_stack.size()-1;
      while (l < r) {
        int mid = l + (r-l)/2;
        if (m_stack[mid][2] < building[2]) l = mid+1;
        else r = mid;
      }
      if (!m_stack.empty()) {
        if (m_stack[l][2] > building[2]) m_stack.insert(m_stack.begin()+l, building);
        else m_stack.insert(m_stack.begin()+l+1, building);
      } else {
        m_stack.push_back(building);
      }
    }
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
      int size = buildings.size();
      vector<pair<int, int>> retval;
      if (!size) return retval;
      deque<vector<int>> m_stack;
      for (int i = 0; i < size; i++) {
        if (m_stack.empty()) {
          retval.push_back(pair<int,int>(buildings[i][0], buildings[i][2]));
          m_stack.push_back(buildings[i]);
        } else {
          while (!m_stack.empty() && m_stack.back()[1] < buildings[i][0]) {
            vector<int> top = m_stack.back();
            m_stack.pop_back();
            if (m_stack.empty()) {retval.push_back(pair<int,int>(top[1],0)); top.clear();}
            else if(m_stack.back()[1] > top[1]) retval.push_back(pair<int,int>(top[1], m_stack.back()[2]));
            else {m_stack.pop_back(); m_stack.push_back(top);}
          }
          insertDeq(m_stack, buildings[i]);
          if (m_stack.back()[2] > retval.back().second) retval.push_back(pair<int,int>(m_stack.back()[0], m_stack.back()[2]));
        }
      }
      while (!m_stack.empty()) {
        vector<int> top = m_stack.back();
        m_stack.pop_back();
        if (m_stack.empty()) retval.push_back(pair<int,int>(top[1],0));
        else if(m_stack.back()[1] > top[1]) retval.push_back(pair<int,int>(top[1], m_stack.back()[2]));
        else {m_stack.pop_back(); m_stack.push_back(top);}
      }
      for (int i = 0; i < retval.size()-1; i++) {
        if (retval[i].first == retval[i+1].first) {retval.erase(retval.begin()+i); i--;}
        else if (retval[i].second == retval[i+1].second) {retval.erase(retval.begin()+i+1); i--;}
      }
      return retval;
    }
};
