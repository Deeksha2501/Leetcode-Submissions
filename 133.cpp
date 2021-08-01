/*
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node* , Node*> mp;
    
    Node* dfs(Node* node){
        if(node == NULL)return NULL;
        if(mp.find(node) != mp.end())return mp[node];
        Node *root = new Node(node->val);
        vector<Node*> ch = node->neighbors;
        vector<Node*> v;
        mp[node] = root;
        for(int i=0 ; i<ch.size() ; i++){
            v.push_back(dfs(ch[i]));
        }
        root->neighbors = v;
        return mp[node] = root;
    }
    
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};