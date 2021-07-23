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
    
    string dfs(TreeNode* root){
        if(root == NULL)return "";
        string s = to_string(root->val);
        if(root->left){
            s = s + "(" + dfs(root->left) + ")";
        }
        if(root->right){
            if(!root->left)s += "()";
            s += "(" + dfs(root->right) + ")";
        }
        return s;
    }
    
    string tree2str(TreeNode* root) {
        if(root == NULL){
            return "";
        }
        return dfs(root);
    }
};