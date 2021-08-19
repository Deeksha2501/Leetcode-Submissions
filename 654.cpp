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
    vector<int> nums;
    TreeNode* dfs(int left , int right){
        // cout<<"\nleft = "<<left<<" right = "<<right;
        if(left > right)return NULL;
        if(left == right)return new TreeNode(nums[left]);
        int in = left;
        for(int i=left ; i<=right ; i++){
            if(nums[in]<nums[i])in = i;
        }
        // cout<<"\nin = "<<in;
        TreeNode *root = new TreeNode(nums[in]);
        root->left = dfs(left , in-1);
        root->right = dfs(in+1 , right);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        return dfs(0 , n-1);
    }
};