class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> pr;
    stack<int> sc;
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        pr.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(pr.size() == 0)return -1;
        while(pr.size()>0){
            sc.push(pr.top());
            pr.pop();
        }
        int x = sc.top();
        sc.pop();
        while(sc.size()>0){
            pr.push(sc.top());
            sc.pop();
        }
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if(pr.size() == 0)return -1;
        while(pr.size()>0){
            sc.push(pr.top());
            pr.pop();
        }
        int x = sc.top();
        while(sc.size()>0){
            pr.push(sc.top());
            sc.pop();
        }
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return pr.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */