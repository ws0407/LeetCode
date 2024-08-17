#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int res = INT_MAX;
    TreeNode* pre = nullptr;
    int getMinimumDifference(TreeNode* root) {
        if (!root) return res;
        int left = getMinimumDifference(root->left);
        if (pre && res > abs(root->val - pre->val)) {
            res = abs(root->val - pre->val);
        }
        pre = root;
        int right = getMinimumDifference(root->right);
        return res;
    }
};