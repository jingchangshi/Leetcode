#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n = nums.size();
      vector<vector<int>> ans;
      if (n<3) {
        return ans;
      }
      // sort the original array
      mergeSort(nums, 0, n-1);
      for (int i=0; i<n-2; i++) {
        if (nums[i]>0) {
          break;
        }
        if (i>0 && nums[i]==nums[i-1]) {
          continue;
        }
        int j = i + 1;
        int k = n - 1;
        while (j<k) {
          int sum = nums[i]+nums[j]+nums[k];
          if (sum==0) {
            vector<int> the3 = {nums[i], nums[j], nums[k]};
            ans.push_back(the3);
            while (j<k && nums[j]==nums[j+1]) {
              j++;
            }
            while (k>j && nums[k]==nums[k-1]) {
              k--;
            }
            j++;
            k--;
          } else if (sum>0) {
            k--;
          } else {
            j++;
          }
        }
      }
      return ans;
    }
    // merge sort
    void mergeSort(vector<int>& nums, int b, int e) {
      if (b>=e) {
        return;
      }
      int mid = (b+e)/2;
      mergeSort(nums, b, mid);
      mergeSort(nums, mid+1, e);
      vector<int> tmp(e-b+1);
      int i = b, j = mid+1, cnt = 0;
      while (i<=mid && j<=e) {
        if (nums[i]<nums[j]) {
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
      for (int k=0; k<cnt; k++) {
        nums[b+k] = tmp[k];
      }
    }
};

int main(void) {
  // vector<int> nums = {-1, 0, 1, 2, -1, -4};
  // vector<int> nums = {-1, 0, 1, 2, -1, 0};
  // vector<int> nums = {-1, 0, 1, 2, 1, -4};
  vector<int> nums = {0, 0, 0};
  // vector<int> nums = {0, 0, 0, 0};
  Solution sol;
  vector<vector<int>> ans = sol.threeSum(nums);
  int n = ans.size();
  for (int i = 0; i < n; i++) {
    cout << "[" << ans[i][0] << ", " << ans[i][1] << ", " << ans[i][2] << "]" << endl;
  }
  return 0;
}
