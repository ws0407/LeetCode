#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * 输入："abbaca"
 * 输出："ca"
 */

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> cs;
        for (char c: s) {
            if (cs.empty() || cs.top() != c) {
                cs.push(c);
            } else {
                cs.pop();
            }
        }
        s = "";
        while (!cs.empty())
        {
            s += cs.top();
            cs.pop();
        }  
        reverse(s.begin(), s.end());
    }
};