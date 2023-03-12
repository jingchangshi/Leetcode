#include <string>
#include <climits>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target;
        for (int i = 0; i < t.size(); i++) {
            target[t[i]]++;
        }
        unordered_map<char, int> window;
        int l = 0;
        int r = 0;
        int num_found = 0;
        int beg;
        int len = INT_MAX;
        int cur_len;
        while (r < s.size()) {
            char c = s[r];
            r++;
            //
            if (target.count(c)) {
                window[c]++;
                if (window[c] == target[c]) {
                    num_found++;
                }
            }
            //
            while (num_found == target.size()) {
                int cur_len = r - l;
                if (cur_len < len) {
                    len = cur_len;
                    beg = l;
                }
                char d = s[l];
                l++;
                //
                if (target.count(d)) {
                    if (window[d] == target[d]) {
                        num_found--;
                    }
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(beg, len);
    }
};

int main(int argc, char **argv)
{
    // string s = "ADOBECODEBANC";
    // string t = "ABC";
    string s = "DBCA";
    string t = "ABC";
    // string s = "A";
    // string t = "AA";
    Solution sol;
    string min_win = sol.minWindow(s, t);
    cout << min_win << endl;
    return 0;
}