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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;
        queue<pair<TreeNode* , long long int > > q;
        q.push({root , 0});
        int m = 1;
        while(!q.empty()){
            int s = q.size();
            long long minn = -1, maxx = -1;
            for(int i=0 ; i<s ; i++){
                // int flag = 0;
                pair<TreeNode* , int> curr = q.front();
                TreeNode* node = (TreeNode*)curr.first;
                long long int ind = (long long int)curr.second;
                
                if(i == 0)minn = ind;
                if(i == s-1)maxx = ind;
                if(node->left!=NULL)q.push({node->left , 2*ind});
                if(node->right!=NULL)q.push({node->right , 2*ind+1});
                
                q.pop();
            }
            m =(int) max(m ,(int)( maxx-minn+1));
        }
        return m;
    }
};