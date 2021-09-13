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
    vector<int> in, post;
    int i;
    
    TreeNode* dfs(int l , int r){
        if(l > r)return NULL;
        if(i < 0)return NULL;
        TreeNode *root = new TreeNode(post[i]);
        int mid = l;
        for(int j=l ; j<=r ; j++){
            if(in[j] == post[i]){
                mid = j;
                break;
            }
        }
        i--;
        root->right = dfs(mid+1 , r);
        root->left = dfs(l , mid-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        in = inorder;
        post = postorder;
        int n = in.size();
        i=n-1;
        return dfs(0 , n-1);
    }
};