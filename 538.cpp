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
    
    int store = 0;
    
    void gst(TreeNode* root){
        if(root == NULL)return;
        gst(root->right);
        root->val += store;
        store = root->val;
        gst(root->left);
        
    }
    
    TreeNode* convertBST(TreeNode* root) {
        gst(root);
        return root;
    }
};