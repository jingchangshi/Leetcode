#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void rotate(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> tmp(nums);
      for (int i=0; i<n; i++) {
        nums[(i+k)%n] = tmp[i];
      }
    }
};

int main(void) {
  vector<int> nums = {-1,-100,3,99};
  int k = 2;
  Solution sol;
  sol.rotate(nums, k);
  int n = nums.size();
  cout << "[";
  for (int i=0; i<n-1; i++) {
    cout << nums[i] << ",";
  }
  cout << nums[n-1] << "]" << endl;
  return 0;
}
