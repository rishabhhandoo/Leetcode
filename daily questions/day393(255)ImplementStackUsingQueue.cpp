class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
;    }
    
    int pop() {
        int size = q.size()-1;
        while(size--)
        {
            int front = q.front();
            q.pop();
            q.push(front);
        }
        if(!q.empty())
        {
            int val = q.front();
            q.pop();
            return val;
        }else
            return -1;
    }
    
    int top() {
        int size = q.size()-1;
        while(size--)
        {
            int front = q.front();
            q.pop();
            q.push(front);
        }
        if(!q.empty())
        {
            int val = q.front();
            q.pop();
            q.push(val);
            return val;
        }else
            return -1;
    }
    
    bool empty() {
        return q.empty();
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