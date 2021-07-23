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
    vector<int> in;
    
    void dfs(TreeNode* root){
        if(root == NULL)return;
        dfs(root->left);
        in.push_back(root->val);
        dfs(root->right);
    }
    
    TreeNode* create(int start , int end){
        if(start > end)return NULL;
        if(start == end){
            return new TreeNode(in[start]);
        }
        int mid = (start+end)/2;
        TreeNode *root = new TreeNode(in[mid]);
        root->left = create(start , mid-1);
        root->right = create(mid+1 , end);
        return root;
    
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL)return NULL;
        dfs(root);
        return create(0 , in.size()-1);
        
    }
};