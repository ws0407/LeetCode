#include <iostream>
#include <vector>
#include <queue>
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
    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& res) {
        if (root == nullptr) return;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && targetSum == root->val) {
            res.push_back(path);
        }
        dfs(root->left, targetSum - root->val, path, res);
        dfs(root->right, targetSum - root->val, path, res);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, path, res);
        return res;
    }
};