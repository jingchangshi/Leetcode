#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int max_len = 0;
      unordered_set<char> subset;
      int n = s.size(), b=0;
      for (int i=0; i<n; i++) {
        while (subset.find(s[i]) != subset.end()) {
          subset.erase(s[b]);
          b++;
        }
        subset.insert(s[i]);
        max_len = max(max_len, i-b+1);
      }
      return max_len;
    }
};

int main(void) {
  Solution sol;
  // string s = "abcabcbb";
  string s = "pwwkew";
  int ans = sol.lengthOfLongestSubstring(s);
  cout << ans << endl;
  return 0;
}
