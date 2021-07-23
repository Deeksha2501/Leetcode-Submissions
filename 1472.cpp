class Node{
    public:
    string val;
    Node *prev;
    Node *next;
    Node(string v){
        val = v;
        next = NULL;
        prev = NULL;
    }
};

class BrowserHistory {
public:
    Node *urls;
    Node *curr;
    BrowserHistory(string homepage) {
        urls = new Node(homepage);
        curr = urls;
    }
    
    void visit(string url) {
        Node *u = new Node(url);
        urls->next = u;
        u->prev = urls;
        urls = u;
    }
    
    string back(int steps) {
        while(steps-- && urls->prev){
            urls = urls->prev;
        }
        return urls->val;
    }
    
    string forward(int steps) {
        while(steps-- && urls->next){
            urls = urls->next;
        }
        return urls->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */