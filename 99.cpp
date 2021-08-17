// 1 2 3 4 5

class Solution {
public:
    TreeNode* first=NULL, *second=NULL, *prev=new TreeNode(INT_MIN);

    void dfs(TreeNode* root){
        if(root == NULL)return;
        dfs(root->left);
        if(root->val < prev->val){
            if(first == NULL){
                first = prev;
                second = root;
            }else{
                second = root;
            }
        }else{
            prev = root;
        }
        dfs(root->right);
    }

    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val , second->val);
    }
};




