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
     // vector<int> mem;
     vector<TreeNode*> dfs(int l , int r){
        vector<TreeNode*> res;
        if(l > r){
            res.push_back(NULL);
            return res;
        }  
        for(int j=l ; j<=r ; j++){
            vector<TreeNode*> left = dfs(l , j-1);
            vector<TreeNode*> right = dfs(j+1 , r);
            
            for(auto l : left){
                for(auto r : right){
                    TreeNode* curr = new TreeNode(j);
                    curr->left = l;
                    curr->right = r;
                    res.push_back(curr);
                }
            }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1 , n);
    }
};