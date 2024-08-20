#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 这题用动态规划的复杂度是 O(m*n)，空间复杂度是 O(m*n)
        // 但是用双指针法的复杂度是 O(m+n)，空间复杂度是 O(1)
        int is = 0, it = 0;
        while (is < s.size() && it < t.size()) {
            if (s[is] == t[it]) {
                is++;
            }
            it++;
        }
        return is == s.size();
    }
};