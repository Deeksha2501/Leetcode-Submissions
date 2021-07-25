class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> mn;
    // int mn;
    
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            mn.push(val);
            return;
        }
        if(val <= mn.top()){
            mn.push(val);
        }
        s.push(val);
    }
    
    void pop() {
        int t = s.top();
        s.pop();
        if(t == mn.top()){
            mn.pop();
        }
    }
    
    int top(){
        return s.top();
    }
    
    int getMin() {
        return mn.top();
    }
};


// min = 5
//     2
//     -3
// if(x < min){
//     s.push(x-min);
//     min = x;
// }

// if(s.top()<0){
//     cout<<min;
//     min = min - s.top();
//     s.pop();
// }


// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */