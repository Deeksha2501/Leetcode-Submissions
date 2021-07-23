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
    unordered_set<int> s;
    
    void dfs(TreeNode *root){
        if(root == NULL)return ;
        s.insert(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    
    bool isUnivalTree(TreeNode* root) {
        dfs(root);
        if(s.size() > 1)return false;
        return true;
    }
};