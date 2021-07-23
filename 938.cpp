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
    int getSum(TreeNode* root, int low, int high){
        if(root == NULL)return 0;
        int sum=0;
        if(root->val <= high && root->val >= low)sum = root->val;
        return sum + getSum(root->left , low , high) + getSum(root->right , low , high);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        return getSum(root , low , high);
    }
};