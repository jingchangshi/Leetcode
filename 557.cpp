#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
  string reverseWords(string s) {
    string ans(s);
    int n = s.size();
    int j=0;
    for (int i=0; i<n; i++) {
      if (s[i]==' ') {
        // we find the whitespace as the delimiter
        for (int k=j; k<i; k++) {
          ans[k] = s[i-1-(k-j)];
        }
        j = i+1;
      }
    }
    // reverse the last word
    for (int k=j; k<n; k++) {
      ans[k] = s[n-1-(k-j)];
    }
    return ans;
  }
};

int main(void) {
  Solution sol;
  string s = "Let's take LeetCode contest";
  string ans = sol.reverseWords(s);
  cout << ans << endl;
}
