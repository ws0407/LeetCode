#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            for (int i = 0; i < size; i++) {
                Node* cur = q.front();
                v.push_back(cur->val);
                q.pop();
                for (Node* n : cur->children) {
                    q.push(n);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};