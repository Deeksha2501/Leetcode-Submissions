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
    vector<vector<int>> res;
    int target;
    
    void dfs(TreeNode* root , vector<int> v , int sum){
        if(root == NULL)return;
        sum += root->val;
        v.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(sum == target)res.push_back(v);
            return;
        }
        dfs(root->left , v , sum);
        dfs(root->right , v , sum);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        dfs(root , {} , 0);
        return res;
    }
};