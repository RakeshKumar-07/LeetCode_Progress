class MyQueue {
public:
    stack<int> s;
    int front = 0;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        stack<int> t;
        while(!s.empty()){
            t.push(s.top());
            s.pop();
        }
        front = t.top();
        t.pop();
        while(!t.empty()){
            s.push(t.top());
            t.pop();
        }
        return front;
    }
    
    int peek() {
        stack<int> t;
        while(!s.empty()){
            t.push(s.top());
            s.pop();
        }
        front = t.top();
        while(!t.empty()){
            s.push(t.top());
            t.pop();
        }
        return front;
    }
    
    bool empty() {
        return s.empty();
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