/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode* , TreeNode*> parent;
    
    void dfs(TreeNode* root , TreeNode* par){
        if(root != NULL){
            parent[root] = par;
            dfs(root->left , root);
            dfs(root->right , root);
        }
    }
    
    void print(queue<TreeNode*> q){
        while(q.size()>0){
            if(q.front() == NULL)cout<<"NULL";
            else cout<<q.front()->val<<" ";
            // cout<<"\n";
            q.pop();
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        if(root == NULL)return res;
        dfs(root , NULL);
        
        queue<TreeNode*> q;
        q.push(NULL);
        q.push(target);
        
        int dist=0;
        
        unordered_set<TreeNode* > seen;
        seen.insert(NULL);
        seen.insert(target);
        
            
        
        while(q.size() > 0){
            TreeNode* curr = q.front();
            // cout<<"\nqueue = ";
            // print(q);
            q.pop();
            if(curr == NULL){
                if(dist == k){
                    while(q.size()>0){
                        // cout<<q.front()->val<<" ";
                        res.push_back(q.front()->val);
                        q.pop();
                    }
                    return res;
                }
                q.push(NULL);
                dist++;
            }else{
                // cout<<curr->val<<" ";
                if(seen.find(curr->left) == seen.end()){
                    seen.insert(curr->left);
                    q.push(curr->left);
                }
                if(seen.find(curr->right) == seen.end()){
                    seen.insert(curr->right);
                    q.push(curr->right);
                }

                TreeNode* par = parent[curr];
                if(seen.find(par) == seen.end()){
                    seen.insert(par);
                    q.push(par);
                }
            }
        }   
         return res;
    }
};