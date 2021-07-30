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
    
    vector<int> pre , in;
    int n, i;
    
    TreeNode* dfs(int st , int end){
        if(i >= n)return NULL;
        if(st > end)return NULL;
        if(st == end){
            i++;
            return new TreeNode(in[st]);
        }
        TreeNode* root = new TreeNode(pre[i]);
        int ii = st;
        for( ; ii<=end ; ii++){
            if(pre[i] == in[ii])break;
        }
        
        i++;
        root->left = dfs(st , ii-1);
        root->right = dfs(ii+1 , end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        in = inorder;
        n = in.size();
        i = 0;
        return dfs(0 , n-1);
    }
};