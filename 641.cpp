class MyCircularDeque {
    int *data;
    int front;
    int rear;
    int capacity;
    int size;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int s) {
        capacity = s;
        data = new int[s];
        front = -1;
        rear = -1;
        size = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int elem) {
        if(size == capacity){
            // cout<<"Deque is Full...\n";
            return false;
        }
        size++;
        if(front == -1){
            front = 0;
            rear = 0;
            // cout<<"\nfront updated to = "<<front;
            data[front] = elem;
            return true;
        }
        front = (capacity+front-1)%capacity;
        // cout<<"\nfront updated to = "<<front;
        data[front] = elem;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int elem) {
        if(size == capacity){
            // cout<<"Deque is Full...\n";
            return false;
        }
        size++;
        if(rear == -1){
            front = 0;
            rear = 0;
            data[rear] = elem;
            // cout<<"\nrear updated to = "<<rear;
            return true;
        }
        rear = (rear+1)%capacity;
         // cout<<"\nrear updated to = "<<rear;
        data[rear] = elem;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(front == -1){
            // cout<<"Deque is Empty..\n";
            return false;
        }
        int temp = data[front];
        size--;
        if(size == 0){
            rear = -1;
            front = -1;
        }
        else
        front = (front+1)%capacity;
        // cout<<"\nfront updated to = "<<front;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(size == 0){
            // cout<<"Deque is Empty..\n";
            return false;
        }
        size--;
        int temp = data[rear];
        if(size == 0){
            rear = -1;
            front = -1;
        }
        else
        rear = (capacity+rear-1)%capacity;
         // cout<<"\nrear updated to = "<<rear;
        return true;
        
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(front == -1){
            // cout<<"Deque is empty..\n";
            return -1;
        }
        return data[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(rear == -1){
            // cout<<"Deque is empty..\n";
            return -1;
        }
        return data[rear];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size==0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
      return size==capacity;      
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */