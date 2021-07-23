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
    bool isBST(TreeNode* root , long long int min , long long int max){
        if(root == NULL)return true;
            
        if(root->val <= min || root->val >= max)return false;
        return isBST(root->left, min , root->val) && isBST(root->right , root->val , max);
        
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL)return true;
        return isBST(root , LLONG_MIN , LLONG_MAX);
    
    }
};