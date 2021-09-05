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
    void print(queue<TreeNode*> q){
        while(!q.empty()){
            if(q.front() == NULL)cout<<" null ";
            else cout<<" "<<q.front()->val<<" ";
            q.pop();
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL)return false;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            int n = q.size();
            bool siblings = false;
            bool cousins = false;
            for(int i=0 ; i<n ; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr == NULL)siblings = false;
                else{
                    // cout<<"\nroot->val = "<<curr->val;
                    if(curr->val == x || curr->val == y){
                        // cout<<"\nc = "<<cousins;
                        // cout<<"\ns = "<<siblings;
                        if(cousins == false)cousins = siblings = true;
                        else return !siblings;
                    }
                    if(curr->left){
                        // cout<<"\npushing = "<<curr->left->val;
                        q.push(curr->left);
                    }
                    if(curr->right){
                        // cout<<"\npushing = "<<curr->right->val;
                        q.push(curr->right);
                    }
                    q.push(NULL);
                    // cout<<"\n";
                    // print(q);
                    // cout<<"\n";
                }
            }
        }
        return false;
    }
};\