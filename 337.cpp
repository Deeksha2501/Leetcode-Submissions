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

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Solution {
    
    unordered_map<pair<TreeNode* , bool> , int , hash_pair> mp;
    
public:
    int dfs(TreeNode* root , bool flag){
        if(root == NULL)return 0;
        
        pair<TreeNode* , bool> p;
        p.first = root;
        p.second = flag;
        
        if(mp.find(p) != mp.end())return mp[p];
        
        int res = dfs(root->left , true) + dfs(root->right , true);
        if(flag){
            return max({
                root->val + dfs(root->left , !flag)  + dfs(root->right , !flag),
                res
            });
        }
        return mp[p] = res;
    }
    
    int rob(TreeNode* root) {
        return max(dfs(root , true) , dfs(root , false));
    }
};