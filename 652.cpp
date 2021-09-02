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
    vector<TreeNode*> vec;
    unordered_map<string , int> mp;
    
    string dfs(TreeNode* root){
        if(!root)return "#";
        string left = dfs(root->left);
        string right = dfs(root->right);
        string s = to_string(root->val) + "-" + left + "-" + right;
        if(mp[s] == 1){
            vec.push_back(root);
        }
        mp[s]++;
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root)return {};
        dfs(root);
        return vec;
    }
};