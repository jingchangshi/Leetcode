#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // Version 1.
    // Calculate all the squares and then sort the array.
    // The time cost is not optimal.
    // vector<int> sortedSquares(vector<int>& nums){
    //   int n = nums.size();
    //   vector<int> nums2(n);
    //   for (int i=0; i<n; i++) {
    //     nums2[i] = nums[i]*nums[i];
    //   }
    //   mergeSort(nums2, 0, n-1);
    //   return nums2;
    // }
    // // merge sort function, inplace.
    // void mergeSort(vector<int>& nums, int b, int e){
    //   if (b >= e) {
    //     return;
    //   }
    //   int mid = (b+e)/2;
    //   mergeSort(nums, b, mid);
    //   mergeSort(nums, mid+1, e);
    //   vector<int> tmp(e-b+1);
    //   int i = b, j = mid + 1, cnt = 0;
    //   // merge sort
    //   while (i<=mid && j <= e) {
    //     if (nums[i] < nums[j]) {
    //       tmp[cnt++] = nums[i++];
    //     } else {
    //       tmp[cnt++] = nums[j++];
    //     }
    //   }
    //   while (i<=mid) {
    //     tmp[cnt++] = nums[i++];
    //   }
    //   while (j<=e) {
    //     tmp[cnt++] = nums[j++];
    //   }
    //   // copy back the array
    //   for (int k=0; k<cnt; k++) {
    //     nums[b+k] = tmp[k];
    //   }
    // }
    // Version 2.
    vector<int> sortedSquares(vector<int>& nums){
      int n = nums.size();
      vector<int> nums2(n);
      if (nums[0]>=0) {
        // all non-negative int
        for (int k=0; k<n; k++) {
          nums2[k] = nums[k]*nums[k];
        }
        return nums2;
      } else if (nums[n-1]<=0) {
        // all non-positive int
        for (int k=0; k<n; k++) {
          nums2[k] = nums[n-1-k]*nums[n-1-k];
        }
        return nums2;
      } else {
        // 0 splits the array
        int mid = 0;
        for (int k = 0; k < n; k++) {
          if (nums[k]>0) {
            mid = k-1;
            break;
          }
        }
        int i = mid, j = mid+1, cnt = 0;
        while (i>=0 && j<=n-1) {
          if (nums[i]*nums[i]<nums[j]*nums[j]) {
            nums2[cnt++] = nums[i]*nums[i];
            i--;
          } else {
            nums2[cnt++] = nums[j]*nums[j];
            j++;
          }
        }
        while (i>=0) {
          nums2[cnt++] = nums[i]*nums[i];
          i--;
        }
        while (j<=n-1) {
          nums2[cnt++] = nums[j]*nums[j];
          j++;
        }
        return nums2;
      }
    }
};

int main(void) {
  // vector<int> nums = {-4,-1,0,3,10};
  vector<int> nums = {-7,-3,2,3,11};
  // vector<int> nums = {3,5,6,10,11};
  // vector<int> nums = {-13,-9,-6,-1,-1};
  Solution sol;
  vector<int> nums2 = sol.sortedSquares(nums);
  int n = nums2.size();
  for (int i=0; i<n-1; i++) {
    cout << nums2[i] << ",";
  }
  cout << nums2[n-1] << endl;
  return 0;
}
