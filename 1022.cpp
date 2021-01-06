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
    int sumRootToLeaf(TreeNode* root , int parent_val = 0) {
        if(root == NULL){
            cout<<"\nreturning value = "<<parent_val;
            return parent_val;
        }
        root->val = root->val + (parent_val*2);
        cout<<"\nvalue of root = "<<root->val;
        if(root->left == NULL || root->right == NULL){
            if(root->right == NULL){
            return sumRootToLeaf(root->left , root->val);
            }else{
                return sumRootToLeaf(root->right , root->val);
            }
        }
        return sumRootToLeaf(root->left , root->val) + sumRootToLeaf(root->right , root->val);
    }
};
