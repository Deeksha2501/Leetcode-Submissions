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
    
    void preorder(TreeNode* root, vector<int> &res){
        
        if(root == NULL)return;
        
        preorder(root->left, res);
        res.push_back(root->val);
        preorder(root->right, res);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* r = NULL, *ans = NULL;
        
        vector<int> res;
        
        preorder(root, res);
        
        for(int i=0 ; i<res.size() ; i++){
            TreeNode* n = new TreeNode(res[i]);
            if(r == NULL){
                r = n;
                ans = r;
                continue;
            }
            r->right = n;
            r = r->right;
        }
        return ans;
        
    }
};