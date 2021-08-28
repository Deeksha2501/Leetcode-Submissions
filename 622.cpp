class MyCircularQueue {
public:
    vector<int> arr;
    int front, rear;
    int cap=0;
    int n;
    
    MyCircularQueue(int k) {
        arr = vector<int>(k);
        n = k;
        front = -1;
        rear = -1;
    }
    
    bool enQueue(int value) {
        if(cap == n)return false;
        rear = (rear+1)%n;
        if(front == -1)front++;
        arr[rear] = value;
        cap++;
        return true;
    }
    
    bool deQueue() {
        if(cap == 0)return false;
        cap--;
        front = (front+1)%n;
        return true;
    }
    
    int Front() {
        if(front == -1 || cap == 0)return -1;
        return arr[front];
    }
    
    int Rear() {
        if(rear == -1 || cap == 0)return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if(cap == 0)return true;
        return false;
    }
    
    bool isFull() {
        if(cap == n)return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */