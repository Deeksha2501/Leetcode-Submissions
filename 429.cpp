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
    vector<vector<int>>  levelOrder(Node* root) {
        
        vector<vector<int>> res;
        if(root == NULL)return res;
        queue<Node* > q;
        q.push(root);
        while(q.size()>0){
            vector<int> v1;
            int s = q.size();
            for(int i=0 ; i<s ; i++){
                Node*curr = q.front();
                vector<Node*> v = curr->children;
                for(int i=0 ; i<v.size() ; i++){
                    q.push(v[i]);
                }
                v1.push_back(curr->val);
                q.pop();
            }
            res.push_back(v1);
        }
        return res;
    }
};