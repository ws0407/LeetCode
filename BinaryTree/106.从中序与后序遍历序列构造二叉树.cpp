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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
        if (postorder.size() == 1) return root;
        int index = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        vector<int> left_inorder(inorder.begin(), inorder.begin() + index);
        vector<int> right_inorder(inorder.begin() + index + 1, inorder.end());
        vector<int> left_postorder(postorder.begin(), postorder.begin() + index);
        vector<int> right_postorder(postorder.begin() + index, postorder.end() - 1);
        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder, right_postorder);
        return root;
    }
};

int main() {
    // vector<int> inorder = {9, 3, 15, 20, 7};
    // vector<int> postorder = {9, 15, 7, 20, 3};
    // TreeNode* root = Solution().buildTree(inorder, postorder);
    // cout << root->val << endl;

    vector<int> a{1,2,3};
    vector<int> b(a.begin(), a.begin() + 1);
    cout << b.size() << endl;

    return 0;
}