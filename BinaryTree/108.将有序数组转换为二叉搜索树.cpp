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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return root;
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (!nums.size()) return nullptr;
        if (nums.size() == 1) return new TreeNode(nums[0]);
        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> left = vector<int>(nums.begin(), nums.begin() + mid);
        vector<int> right = vector<int>(nums.begin()+mid+1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};