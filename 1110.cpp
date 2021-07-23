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
    vector<TreeNode*> res;
    unordered_set<int> s;
        
    TreeNode* dfs(TreeNode* root , bool p){
        if(root == NULL)return NULL;
        root->left = dfs(root->left , false);
        root->right = dfs(root->right , false);
        if(s.find(root->val) != s.end()){
            if(root->left)dfs(root->left , true);
            if(root->right)dfs(root->right , true);
            root = NULL;
            return root;
        }
        if(p)res.push_back(root);
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& td) {
        if(root == NULL)return res;
        for(int i=0 ; i<td.size() ; i++){
            s.insert(td[i]);
        }
        dfs(root , true);
        return res;
    }
};