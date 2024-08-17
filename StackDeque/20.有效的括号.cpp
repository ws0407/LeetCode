#include <iostream>
#include <stack>
#include <map>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> cs;
        map<char, char> ms = {{'[', ']'}, {'(', ')'}, {'{', '}'}};
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
                cs.push(ms[s[i]]);
            } else {
                if (cs.empty() || cs.top() != s[i]) return false;
                cs.pop();
            }
        }
        return cs.empty();
    }
};

int main() {
    string s = "(";
    Solution S;
    cout << S.isValid(s) << endl;
    return 0;
}