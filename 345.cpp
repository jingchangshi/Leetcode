/*
Write a function that takes a string as input and reverse only the vowels of a string.
Example 1:
Given s = "hello", return "holle".
Example 2:
Given s = "leetcode", return "leotcede".
*/
#include <iostream>
#include <string>
#include <set>
#include <vector>
using std::string;
using std::set;
using std::vector;

class Solution {
public:
    string reverseVowels(string s) {
        set<char> VowsTemplate;
        vector<char> VowsInS;
        vector<int> IndexVowsInS;
        int L;

        VowsTemplate.insert('a');
        VowsTemplate.insert('A');
        VowsTemplate.insert('e');
        VowsTemplate.insert('E');
        VowsTemplate.insert('i');
        VowsTemplate.insert('I');
        VowsTemplate.insert('o');
        VowsTemplate.insert('O');
        VowsTemplate.insert('u');
        VowsTemplate.insert('U');

        for (int i = 0; i < s.size(); i++) {
            if (*VowsTemplate.find(s[i]) == s[i]) {
                VowsInS.push_back(s[i]);
                IndexVowsInS.push_back(i);
            }
        }

        L = VowsInS.size();
        for (int i = 0; i < L; i++) {
            s[IndexVowsInS[i]] = VowsInS[L-1-i];
        }

        return s;
    }
};

int main(int argc, char* argv[]){
    Solution test;
    std::cout << test.reverseVowels("leetcode") << std::endl;
    return 0;
}