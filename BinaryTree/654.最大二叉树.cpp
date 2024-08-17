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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        int rootIndex = 0, rootVal = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > rootVal) {
                rootVal = nums[i];
                rootIndex = i;
            }
        }
        TreeNode* root = new TreeNode(rootVal);
        vector<int> left(nums.begin(), nums.begin() + rootIndex);
        vector<int> right(nums.begin() + rootIndex + 1, nums.end());
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }   
};