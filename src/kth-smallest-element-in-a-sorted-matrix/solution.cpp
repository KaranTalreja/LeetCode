class Solution {
  public:
    bool operator() (const pair<int, pair<int,int>> &a, const pair<int, pair<int,int>>& b) const {
      if (a.first > b.first) return true;
      return false;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
      int R = matrix.size();
      if(!R) return -1;
      int C = matrix[0].size();
      typedef priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int,int>>>, Solution> q_t;
      q_t myQ;
      pair<int,pair<int, int>> temp;
      for (int i = 0; i < R; i++) {
        temp.first = matrix[i][0];
        temp.second.first = i;
        temp.second.second = 0;
        myQ.push(temp);
      }
      int retval = 0;
      for (int i = 0; i < k; i++) {
        temp = myQ.top();
        myQ.pop();
        retval = temp.first;
        if (temp.second.second + 1 < C) {
          temp.first = matrix[temp.second.first][temp.second.second+1];
          temp.second.second += 1;
          myQ.push(temp);
        }
      }
      return retval;
    }
};
