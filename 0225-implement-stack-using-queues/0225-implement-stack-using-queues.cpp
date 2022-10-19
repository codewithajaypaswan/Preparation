class MyStack {
public:
    queue<int>s1, s2;
    int t;
    MyStack() {
    }
    
    void push(int x) {
        s1.push(x);
        t = x;
    }
    
    int pop() {
        while(s1.size() > 1) {
            s2.push(s1.front());
            t = s1.front();
            s1.pop();
        }
        int x = s1.front(); s1.pop();
        swap(s1, s2);
        return x;
    }
    
    int top() {
        return t;
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