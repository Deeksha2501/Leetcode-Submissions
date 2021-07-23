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
    int ans=0;
    
    int distribute(TreeNode* root){
        if(root == NULL)return 0;
        int l = distribute(root->left);
        int r = distribute(root->right);
        ans += abs(l) + abs(r);
        return root->val + l + r - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        distribute(root);
        return ans;
        
    }
};
