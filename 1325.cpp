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
    int target;
    
    TreeNode* dfs(TreeNode* root){
        if(root == NULL)return NULL;
        if(root->left != NULL) root->left = dfs(root->left);
        if(root->right != NULL)root->right = dfs(root->right);
        if(root->val == target &&( root->left==NULL && root->right==NULL))
            root = NULL;
        return root;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int t) {
        target = t;
        return dfs(root);
    }
};