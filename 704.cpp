#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int search(vector<int>& nums, int target){
      int e = nums.size()-1;
      int b = 0;
      int i = (b+e)/2;
      while(b<=e) {
        if(nums[i] > target){
          e = i-1;
        } else if (nums[i] < target){
          b = i+1;
        } else {
          return i;
        }
        i = (b+e)/2;
      }
      return -1;
    }
};

int main(){

  Solution sol;
  int arr[] = {-1,0,3,5,9,12};
  vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
  int target = 2;
  int idx;
  idx = sol.search(nums, target);
  cout << idx << endl;
  return 0;
}
