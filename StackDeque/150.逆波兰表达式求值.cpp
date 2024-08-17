#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                if (s == "+") {
                    nums.push(a + b);
                } else if (s == "-") {
                    nums.push(a - b);
                } else if (s == "*") {
                    nums.push(a * b);
                } else if (s == "/") {
                    nums.push(a / b);
                }
            } else {
                nums.push(stoi(s));
            }
        }
        return nums.top();
    }
};