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
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> tree;
        int res = 0;
        if (root== nullptr) return 0;
        tree.push({root, 1});
        while (!tree.empty()){
            auto node_depth = tree.front();
            tree.pop();
            auto node = node_depth.first;
            int depth = node_depth.second;
            if (node->left != nullptr)
            {
                tree.push({node->left, depth+ 1});
            }
            if (node->right != nullptr){
                tree.push({node->right, depth +1});
            }
            res = max(depth, res);
        }
        return res;
    }
};
