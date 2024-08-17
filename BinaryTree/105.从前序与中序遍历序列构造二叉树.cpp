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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        if (preorder.size() == 1) return root;
        int index = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        vector<int> left_inorder(inorder.begin(), inorder.begin() + index);
        vector<int> right_inorder(inorder.begin() + index + 1, inorder.end());
        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + index);
        vector<int> right_preorder(preorder.begin() + 1 + index, preorder.end());
        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);
        return root;
    }
};