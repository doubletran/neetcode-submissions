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
        int maxd= 0;
        if (!root){
            return 0;
        }
        if (root->left){
            maxd = maxDepth(root->left);
        }
        if (root->right){
            maxd =max(maxDepth(root->right), maxd);
        }
        return maxd + 1;
        
    }
};
