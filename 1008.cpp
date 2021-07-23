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
    
    //left, right, root
    
    TreeNode* getBst(vector<int> p , int& in , int& l , int& r){
        if(in >= p.size() || p[in] < l || p[in]>r)return NULL;
        TreeNode *root = new TreeNode(p[in]);
        in++;
        root->left = getBst(p , in , l , root->val);
      root->right = getBst(p , in , root->val , r);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = 0;
        int max = INT_MAX, min = INT_MIN;
        return getBst(preorder, n , min , max);
    }
};