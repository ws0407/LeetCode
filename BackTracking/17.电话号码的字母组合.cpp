#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
    vector<string> res;
    string s;
    int index = 0;
    vector<string> letterCombinations(string digits) {
        if (index == digits.size()) {
            if (s.length()) res.push_back(s);
            return res;
        }

        for (int i = 0; i < letterMap[digits[index] - '0'].length(); i++) {
            s.push_back(letterMap[digits[index] - '0'][i]);
            index++;
            letterCombinations(digits);
            index--;
            s.pop_back();
        }
        return res;
    }
};