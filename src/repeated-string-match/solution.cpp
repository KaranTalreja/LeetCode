class Solution {
  public:
    int repeatedStringMatch(string A, string B) {
      int sizeA = A.size();
      int sizeB = B.size();
      int count = INT_MAX;
      for (int i = 0; i < sizeA; i++) {
        if (A[i] == B[0]) {
          int crossed = 0;
          bool found = true;
          for (int j = 0, k = i; j < sizeB; j++) {
            if (A[k] != B[j]) {
              found = false;
              break;   
            }
            if (j < sizeB-1) {
              k = (k + 1) % sizeA;
              if (k == 0) crossed++;
            }
          }
          if (true == found && count > crossed+1) count = crossed+1;
        }
      }
      return count == INT_MAX ? -1 : count;
    }
};
