#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int maxDepth = INT_MIN;
    int res;
    void dfs(TreeNode* root, int deep) {
        if (!root->left && !root->right) {
            if (deep > maxDepth) {
                maxDepth = deep;
                res = root->val;
            }
            return;
        }
        if (root->left) dfs(root->left, deep+1);
        if (root->right) dfs(root->right, deep+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};