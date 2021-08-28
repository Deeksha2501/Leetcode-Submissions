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
    int target;
    
    int dfs(TreeNode* root , unordered_map<int , int> mp , int sum){
        if(root == NULL)return 0;
        sum += root->val;
        int temp = mp[sum - target];
        mp[sum]++;
        return temp + dfs(root->left , mp , sum) + dfs(root->right , mp , sum);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        unordered_map<int , int> mp;
        mp[0] = 1;
        return dfs(root , mp , 0);
    }
};