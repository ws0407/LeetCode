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
    void dfs(TreeNode* root, string path, vector<string>& res) {
        if (root->left == nullptr && root->right == nullptr) {
            path += to_string(root->val);
            res.push_back(path);
            return;
        }
        path += to_string(root->val) + "->";
        if (root->left != nullptr) dfs(root->left, path, res);
        if (root->right != nullptr) dfs(root->right, path, res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) return res;
        dfs(root, "", res);
        return res;
    }
};
