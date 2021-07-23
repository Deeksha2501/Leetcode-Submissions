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
    
    bool isSame(TreeNode* r1, TreeNode* r2){
        if(!r1 || !r2){
            return r1==NULL && r2==NULL;
        }else if(r1->val == r2->val){
            return isSame(r1->left , r2->left) && isSame(r1->right , r2->right);
        }else{
            return false;
        }
        
    }
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)return false;
        
        else if(isSame(root , subRoot))return true;
        
        else{
            return isSubtree(root->left , subRoot) || isSubtree(root->right , subRoot);
        }
        
    }
};