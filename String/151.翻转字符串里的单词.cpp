#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        int slow = 0, fast = 0;
        while (s[fast] == ' ' && fast < s.size()) fast++;
        while (fast < s.size()) {
            while (s[fast] != ' ' && fast < s.size()) s[slow++] = s[fast++];
            while (s[fast] == ' ' && fast < s.size()) fast++;
            s[slow++] = ' ';
        }
        s.resize(slow - 1);

        cout << "[1]" << s << endl;

        for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--)
            swap(s[i],s[j]);

        cout << "[2]" << s << endl;

        int start = 0;
        for (int end = 0; end <= s.size(); ++end) {
            if (end == s.size() || s[end] == ' ') {
                for (int i = start, j = end - 1; i < j; i++, j--) swap(s[i], s[j]);
                start = end + 1;
            }
        }
        return s;
    }
};


int main() {
    string s = "   the   sky is  blue  ";
    cout << s << endl;
    Solution solution;
    s = solution.reverseWords(s);
    cout << s << endl;
    cout << "len: " << s.size() << endl;
    return 0;
}