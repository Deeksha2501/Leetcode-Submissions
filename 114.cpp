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
    
    TreeNode* dfs(TreeNode* root){
        if(root==NULL)return NULL;
        if(root->left == NULL && root->right == NULL){
            // cout<<"\nreturing = "<<root->val;
            return root;
        }       
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        TreeNode *left = dfs(root->left);
        TreeNode *right = dfs(root->right);
        
        root->left = NULL;
        if(left){
            left->right = r;
            root->right = l;
        }
        else root->right = r;
        
        if(right)return right;
        return left;
    }
    
    void flatten(TreeNode* root) {
        dfs(root);
    }
};