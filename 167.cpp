#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int n = numbers.size();
      int i, m;
      for (i=0; i<n; i++) {
        int rem = target - numbers[i];
        // find rem in the rest of the numbers
        // it is possible that rem is not found in the rest of the numbers
        int b = i+1, e = n-1;
        while (b<=e) {
          m = (b+e)/2;
          if (rem == numbers[m]) {
            // we find it
            break;
          } else if (rem < numbers[m]) {
            e = m-1;
          } else if (rem > numbers[m]) {
            b = m+1;
          }
        } // while (b<=e)
        // if (i==m) {
        //   // we cannot use the same number twice
        //   continue;
        // }
        if (b<=e) {
          // we find the pair
          break;
        }
      }
      vector<int> ans = {i+1,m+1};
      return ans;
    }
};

int main(void) {
  vector<int> numbers = {2,7,11,15};
  int target = 9;
  // vector<int> numbers = {2,3,4};
  // int target = 6;
  // vector<int> numbers = {-1,0};
  // int target = -1;
  // vector<int> numbers = {1,2,3,4,4,9,56,90};
  // int target = 8;
  Solution sol;
  vector<int> ans = sol.twoSum(numbers, target);
  cout << "[" << ans[0] << "," << ans[1] << "]" << endl;
  return 0;
}
