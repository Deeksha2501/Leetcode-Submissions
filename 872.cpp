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
    void dfs(TreeNode *root , vector<int> &v){
        if(!root)return;
        if(root->left == NULL && root->right == NULL)v.push_back(root->val);
        dfs(root->left , v);
        dfs(root->right , v);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL)return true;
        vector<int> v1 , v2;
        dfs(root1 , v1);
        dfs(root2 , v2);
        
        if(v1.size() != v2.size())return false;
        for(int i=0; i<v1.size() ; i++){
            if(v1[i] != v2[i])return false;
            // cout<<"\n"<<v1[i]<<" "<<v2[i];
        }
        return true;
    }
};

