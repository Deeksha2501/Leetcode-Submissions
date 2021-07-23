/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start
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

    

    bool isSymmetric(TreeNode* root) {
        if(root ==NULL)return true;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(left == NULL && right == NULL)return true;
        if(!left || !right)return false;

    }
};
// @lc code=end

