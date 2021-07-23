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
    
    int dfs(TreeNode* root){
        if(root==NULL)return 0;
        int sum=0;
        if(root->val %2 == 0){
            
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            if(l){
                sum += l->left ? l->left->val : 0;
                sum += l->right ? l->right->val : 0;
            }
            if(r){
                sum += r->left ? r->left->val : 0;
                sum += r->right ? r->right->val : 0;
            }
        }
        return sum + dfs(root->left) + dfs(root->right);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root);
    }
};
