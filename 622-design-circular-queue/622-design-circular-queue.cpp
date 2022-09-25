class MyCircularQueue {
public:
    int e = 0;
    int front = -1;
    int rear = -1;
    int n;
    vector<int> arr;
    MyCircularQueue(int k) {
        arr.resize(k,0);
        n = k;
    }
    bool enQueue(int value) {
        if(!isFull()){
            rear = (rear+1)%n; 
            arr[rear] = value;
            if(e==0){
                front++;
            }
            e++;
            return true;    
        }
        return false;
    }
    
    bool deQueue() {
        if(front == rear && rear != -1){
            front = -1;
            rear = -1;
            e = 0;
            return true;
        }
        if(!isEmpty()){
            front = (front+1)%n;
            return true;
        }
        return false;    
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return arr[rear]; 
    }
    
    bool isEmpty() {
        if(front == -1) return true;
        else return false;
    }
    
    bool isFull() {
        if(front - rear == 1 || rear - front == n-1 && rear!=-1) return true;
        else return false;
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