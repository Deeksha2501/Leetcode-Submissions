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
    
    // pair<int , int> freshfind(TreeNode* root){
    //     pair<int, int> res;
    //     if(root == NULL){
    //         res.first=0;
    //         res.second=0;
    //         return res;
    //     }
    //     res.first = 1 + get(root->right , true);
    //     res.second = 1 + get(root->left , false);
    //     return res;
    // }
    
    int ans = 0;
    
    void get(TreeNode* root , bool left , int sum){
        if(root == NULL)return;
        ans = max(ans , sum);
        if(left){
            get(root->left , false , sum+1);
            get(root->right , true , 1 );
        }else{
            get(root->right , true , sum+1);
            get(root->left , false , 1);
        }
    }
    
    
    int longestZigZag(TreeNode* root) {
        if(root == NULL)return 0;
        
        get(root->right , true , 1);
        get(root->left , false , 1);
            
        return ans;

    }
};