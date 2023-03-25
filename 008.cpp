#include <vector>
#include <cstdio>
#include <string>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
  int myAtoi_1(string s) {
    int val = 0;
    int n = s.size();
    if (n == 0) {
      return 0;
    }
    int i;
    char c;
    int sign = 1;
    // We remove the preceding whitespaces
    for (i = 0; i < n; i++) {
      c = s[i];
      if (c != ' ') {
        break;
      }
    }
    if (i == n) {
      return 0;
    }
    // Check if the beginning char is - or 0 or a number.
    if (c == '-') {
      // We continue to find a real number
      sign = -1;
      i++;
    } else if (c == '+') {
      sign = 1;
      i++;
    } else if (c - '0' <= 9 && c - '0' >= 0) {
      // Here we find a real number
      // break;
    } else {
      // Other chars are meaningless
      return 0;
    }
    // Remove the preceding 0
    int k;
    for (k = i; k < n; k++) {
      c = s[k];
      if (c != '0') {
        break;
      }
    }
    // Now we find the beginning real number and the sign is set
    vector<int> nums;
    for (int j = k; j < n; j++) {
      c = s[j];
      int char_num = c - '0';
      if (char_num < 0 || char_num > 9) {
        // It is not a real number. Reach the end.
        break;
      } else {
        nums.push_back(char_num);
      }
    }
    // Now we collect the numbers
    long int sum = 0;
    int power10 = 1;
    for (auto it = nums.rbegin(); it != nums.rend(); it++) {
      if (*it > (INT_MAX - sum) / power10) {
        sum = LONG_MAX;
        break;
      } else {
        sum += *it * power10;
        if (it != nums.rend() - 1) {
          if (power10 > INT_MAX / 10) {
            sum = LONG_MAX;
            break;
          } else {
            power10 *= 10;
          }
        }
      }
    }
    sum *= sign;
    if (sum > INT_MAX) {
      val = INT_MAX;
    } else if (sum < INT_MIN) {
      val = INT_MIN;
    } else {
      val = sum;
    }
    return val;
  }

  bool isDigit(const char c) {
    bool state = false;
    if (c - '0' >= 0 && c - '9' <= 0) {
      state = true;
    }
    return state;
  }

  int myAtoi_2(string s) {
        int n = s.length();
        int idx = 0;
        while (idx < n && s[idx] == ' ') {
            // 去掉前导空格
            idx++;
        }
        if (idx == n) {
            //去掉前导空格以后到了末尾了
            return 0;
        }
        bool negative = false;
        if (s[idx] == '-') {
            //遇到负号
            negative = true;
            idx++;
        } else if (s[idx] == '+') {
            // 遇到正号
            idx++;
        } else if (!isDigit(s[idx])) {
            // 其他符号
            return 0;
        }
        int ans = 0;
        while (idx < n && isDigit(s[idx])) {
            int digit = s[idx] - '0';
            if (ans > (INT_MAX - digit) / 10) {
                // 本来应该是 ans * 10 + digit > Integer.MAX_VALUE
                // 但是 *10 和 + digit 都有可能越界，所有都移动到右边去就可以了。
                return negative ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + digit;
            idx++;
        }
        return negative ? -ans : ans;
    }

};

int main(int argc, char **argv) {
  vector<string> s_vec;
  s_vec.push_back("   -042 with");
  s_vec.push_back("   -042w312");
  s_vec.push_back("00000-42a1234");
  s_vec.push_back("words and 987");
  s_vec.push_back("+-12");
  s_vec.push_back("20000000000000000000");
  s_vec.push_back("2147483646");
  s_vec.push_back("-91283472332");
  Solution sol;
  for (size_t i = 0; i < s_vec.size(); i++) {
    // int val = sol.myAtoi_1(s_vec[i]);
    int val = sol.myAtoi_2(s_vec[i]);
    printf("s_vec[%lu] = %s   \t==> %d\n", i, s_vec[i].c_str(), val);
  }
  return 0;
}