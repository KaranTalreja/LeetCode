class Solution {
  public:
    vector<string> fizzBuzz(int n) {
      vector <string> retVal ;
      stringstream ss;
      for (int i =1; i <= n ; i++) {
        if (i % 3 == 0 && i % 5 == 0)   retVal.push_back("FizzBuzz");
        else if (i % 3 == 0)    retVal.push_back("Fizz");
        else if (i % 5 == 0)    retVal.push_back("Buzz");
        else {
          ss << i;
          retVal.push_back(ss.str());
          ss.str("");
        }
      }
      return retVal;
    }
};
