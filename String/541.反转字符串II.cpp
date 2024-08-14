#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void reverse(string &s, int begin, int end)
    {
        for (int i = 0, j = end; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }

    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.size(); i += (2 * k))
        {
            reverse(s, i, i + k < s.size() ? i + k - 1 : s.size() - 1);
        }
        return s;
    }
};


int main() {

    string s = "abcdefg";
    int k = 2;
    Solution solution;
    s = solution.reverseStr(s, k);
    cout << s << endl;

    return 0;
}