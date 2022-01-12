#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void reverseString(vector<char>& s) {
      int n = s.size();
      for (int i=0; i<n/2; i++) {
        char tmp = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = tmp;
      }
    }
};

int main(void) {
  // vector<char> s = {'h','e','l','l','o'};
  vector<char> s = {'H','a','n','n','a','h'};
  Solution sol;
  sol.reverseString(s);
  int n = s.size();
  for (int i=0; i<n-1; i++) {
    cout << s[i] << ",";
  }
  cout << s[n-1] << endl;
  return 0;
}
