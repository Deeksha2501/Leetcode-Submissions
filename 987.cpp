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
    map<int , vector<pair<int , int>>> mp;
    
    static bool cmp(pair<int, int> a , pair<int , int> b){
        if(a.second == b.second)return a.first < b.first;
        return a.second < b.second;
    }
    
    void dfs(TreeNode* root , int in , int d){
        if(root == NULL)return;
        mp[in].push_back({root->val , d});
        dfs(root->left , in-1 , d+1);
        dfs(root->right , in+1 , d+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)return res;
        dfs(root , 0 , 0);
        for(auto i : mp){
            vector<pair<int , int>> v = i.second;
            sort(v.begin() , v.end() , cmp);
            vector<int> temp;
            for(auto p : v){
                temp.push_back(p.first);
            }
            res.push_back(temp);
        }
        return res;
    }
};