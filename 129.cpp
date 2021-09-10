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
    int dfs(TreeNode* root , int num){
        if(root==NULL){
            return 0;
        }
        num = 10*num + root->val;
        if(root->left == NULL && root->right == NULL)return num;
        return dfs(root->right , num)+dfs(root->left , num);
    }
    
    int sumNumbers(TreeNode* root) {
        return dfs(root , 0);
    }
};