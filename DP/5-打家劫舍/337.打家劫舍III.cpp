/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
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
    vector<int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        return {max(left[0], left[1]) + max(right[0], right[1]), root->val + left[0] + right[0]};
    }
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);    // [不偷根节点的最大值, 偷根节点的最大值]
        return max(res[0], res[1]);
    }
};