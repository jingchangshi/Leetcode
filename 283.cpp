#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
      int n = nums.size();
      // maintain the pointer to the first zero and the pointer to the first non-zero.
      // Slow version
      // int z=0,nz=0,b=0;
      // while (b<n) {
      //   z=b;
      //   while (z<n) {
      //     if (nums[z]==0) {
      //       break;
      //     }
      //     z++;
      //   }
      //   nz=z+1;
      //   while (nz<n) {
      //     if (nums[nz]!=0) {
      //       break;
      //     }
      //     nz++;
      //   }
      //   if (nz<n) {
      //     nums[z] = nums[nz];
      //     nums[nz] = 0;
      //     b = z+1;
      //   } else {
      //     b = n;
      //   }
      // }
      // Maintain the index to which the left are all non-zero.
      int j = 0;
      for (int i=0; i<n; i++) {
        if (nums[i]!=0) {
          int tmp = nums[j];
          nums[j++] = nums[i];
          nums[i] = tmp;
        }
      }
    }
};

int main(void) {
  vector<int> nums = {0,1,0,3,12};
  // vector<int> nums = {1,0,0,3,12};
  int n = nums.size();
  Solution sol;
  sol.moveZeroes(nums);
  for (int i=0; i<n-1; i++) {
    cout << nums[i] << ", ";
  }
  cout << nums[n-1] << endl;
  return 0;
}
