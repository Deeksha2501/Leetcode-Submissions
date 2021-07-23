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
    int mx=0;
    
    pair<int, int> dfs(TreeNode* root){
        if(root == NULL){
            pair<int , int> p(INT_MAX , INT_MIN);
            return p;
        }
        pair<int , int> l = dfs(root->left);
        pair<int , int> r = dfs(root->right);
        // cout<<"\nat root = "<<root->val;
        if(l.first != INT_MAX){
            mx = max(mx , abs(root->val-l.first));
        }
        if(r.first != INT_MAX){
            mx = max(mx , abs(root->val-r.first));
        }
        if(l.second != INT_MIN){
            mx = max(mx , abs(root->val-l.second));
        }
        if(r.second != INT_MIN){
            mx = max(mx , abs(root->val-r.second));
        }
        // mx = max({abs(root->val-l.first) , abs(root->val-l.second) , abs(root->val-r.first) ,  abs(root->val-r.second) , mx});
        pair<int , int> p;
        // cout<<"\t max = "<<mx;
        p.first = min({root->val , l.first , r.first});
        p.second = max({root->val , l.second , r.second});
        return p;
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return mx;
    }
};