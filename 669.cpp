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
    int low, high;
    TreeNode* trim(TreeNode* root){
        if(root ==  NULL)return NULL;
        if(root->val > high)return trim(root->left);
        if(root->val < low)return trim(root->right);
        root->left = trim(root->left);
        root->right = trim(root->right);
        return root;
    }
    
    TreeNode* trimBST(TreeNode* root, int l, int h) {
        low=l,high=h;
        return trim(root);
    }
};