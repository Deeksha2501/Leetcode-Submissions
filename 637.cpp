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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root == NULL)return res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0){
            vector<double> v;
            int s = q.size();
            for(int i=0 ; i<s ; i++){
                TreeNode *curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            double sum = 0;
            for(int i=0 ; i<v.size() ; i++){
                sum += v[i];
            }
            res.push_back(sum/v.size());
        }
        return res;
    }
    
};
