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
    bool dfs(TreeNode* root){
        if(root == NULL)return false;
        bool l = dfs(root->left);
        bool r = dfs(root->right);
        if(l == false)root->left = NULL;
        if(r == false)root->right = NULL;
        if(root->val == 0 && l == false && r == false)return false;
        return true;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(dfs(root) == false)root = NULL;
        return root;
    }
};