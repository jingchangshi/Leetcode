#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int searchInsert(vector<int>& nums, int target) {
      int n = nums.size();
      // if (target < nums[0]) {
      //   // target is out of range
      //   return 0;
      // } else if (target > nums[n-1]) {
      //   // target is out of range
      //   return n;
      // } else {
      //   // target is within the range
      //   int i = 0;
      //   while (i<n) {
      //     if (target <= nums[i]) {
      //       break;
      //     }
      //     i++;
      //   }
      //   return i;
      // }
      int i = 0;
      while (i<n) {
        if (target <= nums[i]) {
          break;
        }
        i++;
      }
      return i;
    }
};

int main() {
  // vector<int> nums = {1,3,5,6};
  // int target = 0;
  // vector<int> nums = {1,3,5,6};
  // int target = 7;
  // vector<int> nums = {1,3,5,6};
  // int target = 2;
  // vector<int> nums = {1,3,5,6};
  // int target = 5;
  vector<int> nums = {1};
  int target = 0;
  Solution sol;
  cout << sol.searchInsert(nums, target) << endl;
  return 0;
}
