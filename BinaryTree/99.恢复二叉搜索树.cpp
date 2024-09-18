#include <iostream>
#include <vector>
#include <stack>

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
    void recoverTree(TreeNode* root) {
        // 中序遍历，维护一个栈
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        while (!st.empty()) {
            while (!cur) {
                st.push(cur);
                cur = cur->left;
            }
            // 处理中间结点
            cur = st.top();
            st.pop();
            if (prev && cur->val < prev->val){
                if (!left) left = prev;
                else {
                    right = cur;
                    break;
                }
            }
            prev = cur;
            // 处理右节点
            cur = cur->right;
        }
        if (!left && !right) swap(left, right);
    }
};