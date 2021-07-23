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
    int count = 0;
    
    void fillM(TreeNode* root , unordered_map<int , int> &m){
        if(root == NULL)return;
        m[root->val]++;
        count = max(count, m[root->val]);
        fillM(root->left , m);
        fillM(root->right , m);
    }
    
    vector<int> findMode(TreeNode* root) {
        unordered_map<int , int> m;
        
        fillM(root , m);
        
        vector<int> res;
        
        for(auto it : m){
            if(it.second == count)    {
                res.push_back(it.first);
            }
        }
        
        return res;
        
    }
};