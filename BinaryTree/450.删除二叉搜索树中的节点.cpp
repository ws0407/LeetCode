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
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) return root; 
        if (root->val == key) {
            if (!root->left && !root->right) return nullptr;
            if (!root->right) {
                TreeNode *n = root->left;
                delete root;
                return n;
            }
            if (!root->left) {
                TreeNode *n = root->right;
                delete root;
                return n;
            }
            TreeNode* cur = root->right;
            while (cur->left) cur = cur->left;
            cur->left = root->left;
            cur = root->right;
            delete root;
            return cur;
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        else root->right = deleteNode(root->right, key);
        return root;
    }
};