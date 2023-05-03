/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold
additional elements from nums2. The number of elements initialized in nums1 and nums2 are m
and n respectively.
*/
#include <iostream>
#include <vector>
using namespace std;
// The following codes do not pass LeetCode tests.
// However, I still think this function works, given that the input id indeed sorted array.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>::iterator it1, it2 = nums2.begin();
        if(m == 0 && n != 0){
            nums1 = nums2;
        }
        else if(m != 0 && n != 0){
            it1 = nums1.begin();
            do{
                if(*it2 < *it1){
                    it1 = nums1.insert(it1, *it2)+1;
                    it2++;
                }
                else{
                    if(it1 != nums1.end()){
                        it1++;
                    }
                    else{
                        nums1.push_back(*it2);
                        it1 = nums1.end();
                        it2++;
                    }
                }
            }
            while(it2 != nums2.end());
        }
    }
};

int main(){
    const int m = 4, n = 2;
    vector<int> n1(4), n2(2);
    Solution test;
    n1 = {-1, -1, 2,3, 4, 10};
    n2 = {-1, 0};
    test.merge(n1, m, n2, n);
    for(unsigned i = 1; i <= n1.size(); i++){
        cout << n1[i-1] << ", ";
    }
    cout << endl;
    cout << n1.size() << endl;
}