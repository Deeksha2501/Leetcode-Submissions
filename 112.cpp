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
    bool dfs(TreeNode* root, int targetSum) {
        // if(root == NULL && targetSum == 0)return true;
        if(root->val == targetSum && !root->left && !root->right)return true;
        bool flag = false;
        if(root->left)flag |= dfs(root->left , targetSum-root->val);
        if(root->right)flag |= dfs(root->right , targetSum-root->val);
        return flag;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return false;
        return dfs(root , targetSum);
    }
};

