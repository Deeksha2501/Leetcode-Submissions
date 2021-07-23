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
    int res = INT_MIN;
    
    int height(TreeNode* root){
        if(root == NULL)return 0;
        int l = height(root->left);
        int r = height(root->right);
        int h = 1 + l + r;
        res = max(h , res);
        return 1 + max(l , r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return res-1;
    }
};