#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    // int numDecodings(string s) {
    //   if (s[0] == '0') {
    //     return 0;
    //   }
    //   int n1;
    //   int n2;
    //   int n = s.size();
    //   if (n == 1) {
    //     n1 = 1;
    //     n2 = 0;
    //   } else {
    //     // n >= 2
    //     n1 = numDecodings(s.substr(1));
    //     if (s[0] > '2') {
    //       n2 = 0;
    //     } else if (s[0] == '2' && s[1] > '6') {
    //       n2 = 0;
    //     } else {
    //       if (n == 2) {
    //         n2 = 1;
    //       } else {
    //         // n > 2
    //         n2 = numDecodings(s.substr(2));
    //       }
    //     }
    //   }
    //   return n1 + n2;
    // }

    int numDecodings(string s) {
      int cnt = 0;
      if(s.size() == 0 || (s.size() == 1 && s[0] == '0')) return 0;
      if(s.size() == 1) return 1;
      vector<int> dp(s.size() + 1, 0);
      dp[0] = 1;
      for(int i = 0; i < s.size(); ++i) {
          dp[i+1] = s[i] == '0' ? 0 : dp[i];
          if(i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))){
              dp[i+1] += dp[i-1];
          }
      }
      return dp.back();
    }
};

int main(void) {
  string input;
  // input = "111";
  // input = "11106";
  // input = "06";
  // input = "226";
  // input = "10";
  // input = "27";
  // input = "1201234";
  // input = "123123";
  input = "111111111111111111111111111111111111111111111";
  Solution sol;
  int res = sol.numDecodings(input);
  cout << res << endl;
  return 0;
}
