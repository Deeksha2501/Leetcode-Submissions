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
class BSTIterator {
public:
    vector<int> in;
    int i;
    
    void dfs(TreeNode* root){
        if(root == NULL)return;
        dfs(root->left);
        in.push_back(root->val);
        dfs(root->right);
    }
    
    
    BSTIterator(TreeNode* root) {
        in.push_back(-1);
        dfs(root);
        i = 0;
    }
    
    int next() {
        i++;
        return in[i];
    }
    
    bool hasNext() {
        if(i >= in.size()-1)return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */