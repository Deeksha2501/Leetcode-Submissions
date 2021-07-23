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
    
    int depth(Node* root){
        if(root == NULL)return 0;
        vector<Node*> v = root->children;
        int m = 0;
        for(int i=0 ; i<v.size() ; i++){
            m = max(m , depth(v[i]));
        }
        return 1 + m;
    }
    
    int maxDepth(Node* root) {
        return depth(root);
    }
};