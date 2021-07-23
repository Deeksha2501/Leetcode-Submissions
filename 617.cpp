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
    TreeNode* merge(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)return NULL;
        if(!root1)return root2;
        if(!root2)return root1;
        int sum = 0;
        TreeNode* head = new TreeNode(sum);
        if(root1)sum += root1->val;
        if(root2)sum += root2->val;
        head->val = sum;
        head->left = merge(root1->left , root2->left);
        head->right = merge(root1->right , root2->right);
        return head;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1 , root2);
    }
};