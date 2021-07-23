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
    int sum = 0, maxm=0;
    
    int height(TreeNode* root){
        if(root == NULL)return 0;
        return 1 + max(height(root->left) , height(root->right));
    }
    
    void dfs(TreeNode* root , int depth){
        if(root == NULL)return;
        if(depth == maxm)sum += root->val;
        else{
            dfs(root->left , depth+1);
            dfs(root->right , depth+1);
        }
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL)return 0;
        maxm = height(root);
        dfs(root , 1);
        return sum;
        
        // if(root->left == NULL && root->right == NULL)return root->val;
        // return deepestLeavesSum(root->left) + deepestLeavesSum(root->right);
    }
};