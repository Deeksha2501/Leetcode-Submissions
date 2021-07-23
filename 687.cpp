class Solution {
public:
    int res = 0;
    
    int dfs(TreeNode* root){
        if(root == NULL)return 0;
        int data = root->val;
        int left=dfs(root->left), right=dfs(root->right);
        int ll=0, rr=0;
        if(root->left && data == root->left->val){
            ll = 1 + left;
        }
        if(root->right && data == root->right->val){
            rr = 1 + right;
        }
        
        res = max(res , ll+rr);
        return max(ll , rr);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res;
    }
};