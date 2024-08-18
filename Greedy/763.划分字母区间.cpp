#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> pos(26, 0);
        vector<int> res;
        for (int i = s.size()-1; i >= 0; i--) if (!pos[s[i]-'a']) pos[s[i]-'a'] = i;
        int left = 0, right = pos[s[0]-'a'], idx = 0;
        while (left < s.size()){
            if (left == right ) {
                res.push_back(left - idx + 1);
                idx = left + 1;
            }
            left++;
            if (left < s.size()) right = right < pos[s[left]-'a'] ? pos[s[left]-'a'] : right;
        }
        return res;
    }
};