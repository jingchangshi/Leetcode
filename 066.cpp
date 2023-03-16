#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 遍历所有单词，计算当前行单词+空格的长度，超过了最大值就换行。
// 直到最后一行，需要左对齐，补齐空格到最大长度。

class Solution {
  public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
      vector<string> res;
      int n = words.size();
      // int max_sum = maxWidth + 1;
      int ib = 0;
      int ie = 0;
      while (ie < n) {
        // The length of the current line
        int sum = 0;
        ib = ie;
        // Add word to the current line
        while (ie < n && sum + words[ie].size() + ie - ib <= maxWidth) {
          sum += words[ie].size();
          ie++;
        }
        // 
        string line;
        int nw = ie - ib;
        int ns = maxWidth - sum;
        if (ie == n) {
          // The last line
          line += words[ib];
          for (int i = ib + 1; i < ie; i++) {
            line += ' ' + words[i];
          }
          line += string(ns - (nw - 1), ' ');
        } else {
          // ie < n
          if (nw == 1) {
            line += words[ib] + string(ns, ' ');
          } else {
            int avers = ns / (nw - 1);
            int extrs = ns % (nw - 1);
            // line += words[ib];
            for (int i = ib; i < ib + extrs; i++) {
              line += words[i] + string(avers+1, ' ');
            }
            for (int i = ib + extrs; i < ie - 1; i++) {
              line += words[i] + string(avers, ' ');
            }
            line += words[ie - 1];
          }
        }
        res.push_back(line);
      }
      return res;
    }
    // 第一次做题时绕到一起的思路，结果处理不清了。
      // while (ie < n) {
      //   int m = 0;
      //   ib = ie;
      //   while (sum < max_sum) {
      //     if (ie == n) {
      //       // exceeds the upper bound
      //       break;
      //     }
      //     m = words[ie].size();
      //     // m + 1 accounts for the whitespace
      //     sum += m + 1;
      //     ie++;
      //   }
      //   string line;
      //   // sum exceeds maxWidth+1
      //   if (sum == max_sum) {
      //     // exactly match without the trailing whitespace
      //     // add the string to the vector
      //     for (int k = ib; k < ie - 1; k++) {
      //       line += words[k] + ' ';
      //     }
      //     line += words[ie - 1];
      //   } else {
      //     // sum > max_sum
      //     // if (ie < n) {
      //       // roll back 1 string and an additional whitespace
      //       ie--;
      //       sum -= m + 1 + 1;
      //     // }
      //     // calculate the number of whitespace appended to a string
      //     int nw = maxWidth - sum;
      //     // Count the number of string. The rightmost string should be omitted.
      //     int ns = ie - ib - 1;
      //     int nw_base = nw / ns;
      //     int nw_rem = nw - nw_base * ns;
      //     int iw_rem = 0;
      //     // if (ie < n) {
      //       for (int k = ib; k < ie - 1; k++) {
      //         line += words[k] + ' ';
      //         if (nw_base > 0) {
      //           for (int iwb = 0; iwb < nw_base; iwb++) {
      //             line += ' ';
      //           }
      //         }
      //         if (iw_rem < nw_rem) {
      //           line += ' ';
      //           iw_rem++;
      //         }
      //       }
      //       line += words[ie - 1];
      //     // } else {
      //     if (ie == n - 1) {
      //       // ie == n - 1
      //       // for (int k = ib; k < ie; k++) {
      //       //   line += words[k] + ' ';
      //       // }
      //       res.push_back(line);
      //       line.clear();
      //       line += words[ie] + ' ';
      //       nw = maxWidth - words[ie].size() - 1;
      //       for (int k = 0; k < nw; k++) {
      //         line += ' ';
      //       }
      //       ie++;
      //     }
      //     // }
      //   }
      //   res.push_back(line);
      // }


};

int main(void) {
  // vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
  // int maxWidth = 16;
  vector<string> words = {"What","must","be","acknowledgment","shall","be"};
  int maxWidth = 16;
  Solution sol;
  vector<string> res = sol.fullJustify(words, maxWidth);
  for (int i = 0; i < res.size() - 1; i++) {
    cout << res[i] << "," << endl;
  }
  cout << res[res.size() - 1] << endl;
  return 0;
}
