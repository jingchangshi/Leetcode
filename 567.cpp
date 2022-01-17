#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    bool checkInclusion(string s1, string s2) {
      int t1 = s1.size();
      int t2 = s2.size();
      if (t1 > t2) {
        return false;
      }
      vector<int> cnt1(26,0), cnt2(26,0);
      for (int i=0; i<t1; i++) {
        cnt1[s1[i]-'a']++;
        cnt2[s2[i]-'a']++;
      }
      // check if the first substring is matched
      bool all_eq = true;
      // bool core_eq = false;
      for (int i=0; i<26; i++) {
        if (cnt1[i] != cnt2[i]) {
          all_eq = false;
          break;
        }
      }
      if (all_eq) {
        return true;
      }
      // move the window
      for (int i=t1; i<t2; i++) {
        cnt2[s2[i]-'a']++;
        cnt2[s2[i-t1]-'a']--;
        all_eq = true;
        for (int j=0; j<26; j++) {
          if (cnt1[j] != cnt2[j]) {
            all_eq = false;
            break;
          }
        }
        if (all_eq) {
          return true;
        }
      }
      return false;
    }
};

int main (void) {
  Solution sol;
  string s1 = "ab";
  string s2 = "eidbaooo";
  // string s1 = "ab";
  // string s2 = "eidboaoo";
  cout << sol.checkInclusion(s1, s2) << endl;
  return 0;
}
