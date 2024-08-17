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
    int cnt = 0, maxCnt = -1;
    TreeNode* pre = nullptr;
    vector<int> res;

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        cnt = pre && pre->val == root->val ? cnt + 1 : 1;
        pre = root;
        if (cnt == maxCnt) res.push_back(root->val);
        if (cnt > maxCnt) {
            maxCnt = cnt;
            res.clear();
            res.push_back(root->val);
        }
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
};