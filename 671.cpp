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
    int val ;
    
    int dfs(TreeNode* root){
        if(root == NULL)return -1;
        if(root->val != val)return root->val;
        if(root->left == NULL && root->right == NULL){
            return -1;
        }
        if(root->val != root->left->val)return root->left->val;
        if(root->val != root->left->val)return root->right->val;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if( l == -1 && r == -1)return -1;
        if(l != -1. && r != -1)
        return min(l , r);
        if(l != -1)return l;
        else return r;
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL)return -1;
        val = root->val;
        return dfs(root);
    }
};