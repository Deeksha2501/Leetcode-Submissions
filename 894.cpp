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
    unordered_map<int , vector<TreeNode*> >m;
    
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> res;
        if(n == 0)return res;
        TreeNode* root = new TreeNode(0);
        if(n == 1){
            res.push_back(root);
            return res;
        }
        
        if(m.find(n) != m.end())return m[n];
        
        for(int k=1 ; k<n-1 ; k++){
            vector<TreeNode*> l= allPossibleFBT(k);
            vector<TreeNode*> r = allPossibleFBT(n-k-1);
            for(int i=0 ; i<l.size() ; i++){
                for(int j=0 ; j<r.size() ; j++){
                    TreeNode* root = new TreeNode(0);
                    root->left = l[i];
                    root->right = r[j];
                    res.push_back(root);
                }
            }
        }
        
        return m[n] = res;
    }
};


//[[0,0,0,0,0,null,null,0,0],[0,0,0,0,0,null,null,0,0],[0,0,0,0,0,null,null,0,0],[0,0,0,0,0,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
