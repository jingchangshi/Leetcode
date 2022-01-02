#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int bad_ = -1;
    bool isBadVersion(int version) {
      if (version >= bad_) {
        return true;
      } else {
        return false;
      }
    }

    int firstBadVersion(int n){
      int b = 1, e = n;
      int i = b;
      while (b<e){
        // cout << "[" << b << ", " << e << "]" << endl;
        i = b/2+e/2;
        if (isBadVersion(i)) {
          e = i;
        } else {
          b = i+1;
        }
      }
      return e;
    }
};

int main(){
  Solution sol;
  // int n = 5;
  // sol.bad_=4;
  // int n = 9;
  // sol.bad_=3;
  int n = 2126753390;
  sol.bad_=1063376697;
  int bad = -1;
  bad = sol.firstBadVersion(n);
  cout << bad << endl;
  return 0;
}
