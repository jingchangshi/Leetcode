#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    int calcRowIdx(const int i, const int n) {
      int mod = 2 * (n - 1);
      int rem = i % mod;
      int r;
      if (rem < n) {
        r = rem;
      } else {
        r = mod - rem;
      }
      return r;
    }
    string convert(string s, int numRows) {
      if (numRows == 1) return s;
      vector<string> zstr;
      zstr.resize(numRows);
      int n = s.size();
      int i = 0;
      int r = 0;
      while (i < n) {
        // r=0
        char c;
        r = calcRowIdx(i, numRows);
        c = s[i];
        i++;
        zstr[r] += c;
      }
      string res;
      for (r = 0; r < numRows; r++) {
        res += zstr[r];
      }
      return res;
    }
};

int main(void) {
  string input;
  int n;
  // input = "PAYPALISHIRING";
  // n = 3;
  // input = "PAYPALISHIRING";
  // n = 4;
  input = "A";
  n = 1;
  Solution sol;
  string res = sol.convert(input, n);
  cout << res << endl;
  return 0;
}
