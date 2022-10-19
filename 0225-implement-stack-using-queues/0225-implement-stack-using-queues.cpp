class MyStack {
public:
    queue<int>s1, s2;
    MyStack() {
        
    }
    
    void push(int x) {
        s2.push(x);
        while(!s1.empty()) {
            s2.push(s1.front()); s1.pop();
        }
        while(!s2.empty()) {
            s1.push(s2.front()); s2.pop();
        }
    }
    
    int pop() {
        int x = s1.front(); s1.pop();
        return x;
    }
    
    int top() {
        return s1.front();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */