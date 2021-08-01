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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)return 0;
        queue<TreeNode*> q;
        int sum=0;
        q.push(root);
        while(q.size()>0){
            int n = q.size();
            for(int i=0 ; i<n ; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left){
                    if(curr->left->left==NULL && curr->left->right==NULL)
                    sum += curr->left->val;
                    q.push(curr->left);
                }
                if(curr->right)q.push(curr->right);
            }
        }
        return sum;
    }
};