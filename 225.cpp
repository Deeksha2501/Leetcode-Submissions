class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1,q2 ;
    
    
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
        while(q1.empty() == false){
            q2.push(q1.front());
            q1.pop();
        }
        q1 = q2;
        while(q2.empty() == false){
            q2.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.empty())return -1;
        int temp= q1.front();
        q1.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        if(q1.empty())return -1;
        int temp= q1.front();
        return temp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.size() == 0;
    }
};

// '4'
//  <- 3 2 1 <-
//  <- 4 3 2 1 <-
    
    
    
    
    
    


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */