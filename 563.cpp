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
    int sum = 0;
    
    int dfs(TreeNode* root){
        if(root == NULL)return 0;
        if(root->right == NULL && root->left == NULL){
            int temp = root->val;
            // root->val = 0;
            // cout<<"\nvalue set from "<<temp<<" to "<<root->val;
            return temp;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        // int temp = root->val;
        // root->val = abs(left-right);
        // cout<<"\nvalue set from "<<temp<<" to "<<root->val;
        sum += abs(left-right);
        return left + right + root->val;
    }
    
    int findTilt(TreeNode* root) {
        if(root == NULL)return 0;
        dfs(root);
        return sum;
    }
};