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
    vector<string> res;
    
    void dfs(TreeNode* root , string str){
        if(root == NULL){
            res.push_back(str);
            return;
        }
        if(root->left == NULL && root->right == NULL){
            res.push_back(str + to_string(root->val));
            return;
        }
        
        string s = str + to_string(root->val) + "->";
        
        if(root->left)dfs(root->left , s);
        if(root->right)dfs(root->right , s);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root , "");
        return res;
    }
};