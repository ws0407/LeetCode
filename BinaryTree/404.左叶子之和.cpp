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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == NULL && root->right== NULL) return 0;
        int left;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            left = root->left->val;
        } else {
            left = sumOfLeftLeaves(root->left);
        }
        return left + sumOfLeftLeaves(root->right);
    }
};