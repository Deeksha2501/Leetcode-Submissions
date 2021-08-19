long res = 0, total = 0, sub;
    int maxProduct(TreeNode* root) {
        total = s(root), s(root);
        return res % (int)(1e9 + 7);
    }

    int s(TreeNode* root) {
        if (!root) return 0;
        sub = root->val + s(root->left) + s(root->right);
        res = max(res, sub * (total - sub));
        return sub;
    }



//overflow(RUNTIME ERROR)
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
    long long total;
    long long MOD = 10e9 + 7;
    long long res = INT_MIN;
    
    long long sumR(TreeNode* root){
        if(root == NULL)return 0;
        return root->val + sumR(root->left) + sumR(root->right);
    }
    
    long long maxP(TreeNode* root){
        if(root == NULL)return 0;
        long long leftS = maxP(root->left);
        long long rightS = maxP(root->right);
        long long one = root->val + leftS + rightS;
        long long second = total - one;
        res = max(res , (one*second));
        return one;
    }
    
    int maxProduct(TreeNode* root) {
        if(root == NULL)return 0;
        total = sumR(root);
        maxP(root);
        return (int)res%MOD;
    }
};