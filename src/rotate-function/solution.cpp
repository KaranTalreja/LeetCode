class Solution {
  public:
    int maxRotateFunction(vector<int>& A) {
      int sumOfAll = 0;
      int F = 0;
      for (int i = 0; i < A.size(); i++) {
        sumOfAll += A[i];
        F += i*A[i];
      }
      int max = F;
      int size = A.size();
      for (int i = size-1; i >= 0; i--) {
        F = F + sumOfAll - size*A[i];
        if (max < F) max = F;
      }
      return max;
    }
};
