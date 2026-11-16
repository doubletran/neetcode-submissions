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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> tree;
        if (root== nullptr) return nullptr;
        int low = min(p->val, q->val);
        int high = max(p->val, q->val);
        tree.push(root);
        while (!tree.empty()){
            auto node = tree.front();
            tree.pop();
            if (low <= node->val){
                if (high >= node->val){
                    return node;
                }
                if (node->left){
                    tree.push(node->left);
                }
            }
            else if(node->right){
                tree.push(node->right);
            }
        }
        return nullptr;
    }
};
