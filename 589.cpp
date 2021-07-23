/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    
    void dfs(Node* root){
        if(root == NULL)return;
        ans.push_back(root->val);
        vector<Node*> v = root->children;
        for(int i=0 ; i<v.size() ; i++){
            dfs(v[i]);
        }
        
    }
    
    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
};