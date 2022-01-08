#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> sortedSquares(vector<int>& nums){
      int n = nums.size();
      vector<int> nums2(n);
      for (int i=0; i<n; i++) {
        nums2[i] = nums[i]*nums[i];
      }
      mergeSort(nums2, 0, n-1);
      return nums2;
    }
    // merge sort function, inplace.
    void mergeSort(vector<int>& nums, int b, int e){
      if (b >= e) {
        return;
      }
      int mid = (b+e)/2;
      mergeSort(nums, b, mid);
      mergeSort(nums, mid+1, e);
      vector<int> tmp(e-b+1);
      int i = b, j = mid + 1, cnt = 0;
      // merge sort
      while (i<=mid && j <= e) {
        if (nums[i] < nums[j]) {
          tmp[cnt++] = nums[i++];
        } else {
          tmp[cnt++] = nums[j++];
        }
      }
      while (i<=mid) {
        tmp[cnt++] = nums[i++];
      }
      while (j<=e) {
        tmp[cnt++] = nums[j++];
      }
      // copy back the array
      for (int k=0; k<cnt; k++) {
        nums[b+k] = tmp[k];
      }
    }

};

int main(void) {
  // vector<int> nums = {-4,-1,0,3,10};
  vector<int> nums = {-7,-3,2,3,11};
  Solution sol;
  vector<int> nums2 = sol.sortedSquares(nums);
  int n = nums2.size();
  for (int i=0; i<n-1; i++) {
    cout << nums2[i] << ",";
  }
  cout << nums2[n-1] << endl;
  return 0;
}
