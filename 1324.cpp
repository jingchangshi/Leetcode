#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    vector<string> printVertically(string s) {
      vector<string> res;
      vector<string> word_list;
      res.push_back("");
      word_list.push_back("");
      int iw = 0;
      int max_len = 0;
      // Extract the words and count the max length of the words
      for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == ' ') {
          // Here it is the delimiter
          int len = word_list[iw].size();
          if (len > max_len) {
            max_len = len;
          }
          iw++;
          word_list.push_back("");
          continue;
        }
        word_list[iw] += c;
      }
      //
      int len = word_list[iw].size();
      if (len > max_len) {
        max_len = len;
      }
      res.resize(max_len);
      //
      int nw = word_list.size();
      for (int r = 0; r < max_len; r++) {
        for (iw = 0; iw < nw; iw++) {
          string word = word_list[iw];
          char c;
          if (r >= word.size()) {
            c = ' ';
          } else {
            c = word[r];
          }
          res[r] += c;
        }
      }
      // Remove the trailing whitespaces
      for (int r = 1; r < max_len; r++) {
        string &word = res[r];
        for (int j = word.size()-1; j >= 0; j--) {
          char c = word[j];
          if (c == ' ') {
            word.pop_back();
          } else {
            break;
          }
        }
      }
      return res;
    }
};

int main(void) {
  string input;
  // input = "HOW ARE YOU";
  // input = "TO BE OR NOT TO BE";
  // input = "CONTEST IS COMING";
  input = "HOW IS IT GOING";
  vector<string> res;
  Solution sol;
  res = sol.printVertically(input);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}
