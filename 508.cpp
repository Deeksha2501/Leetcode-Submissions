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
    unordered_map<int , int> mp;
    
    int dfs(TreeNode* root){
        if(root == NULL)return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int sum = root->val + left + right;
        mp[sum]++;
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        vector<vector<int>>v;
        for(auto it : mp){
            v.push_back({it.second , it.first});
        }
        sort(v.begin() , v.end());
        if(v.size() == 0)return {};
        int val = v.back()[0];
        int i = v.size()-1;
        while(i >= 0){
            if(v[i][0] == val)res.push_back(v[i][1]);
            else break;
            i--;
        }
        return res;
    }
};