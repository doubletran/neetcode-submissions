/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> tree;
        vector<vector<int>>res;
        if (root == nullptr) return res;
        tree.push({root});
        while (!tree.empty()){
            int count = tree.size();
            vector<int>levelNode;
            for (int i = 0; i < count; ++i){
                auto node = tree.front();
                tree.pop();
                if (node->left) tree.push(node->left);
                if (node->right) tree.push(node->right);
                levelNode.push_back(node->val);
            }
            res.push_back(levelNode);
        }
        return res;
    }
};
