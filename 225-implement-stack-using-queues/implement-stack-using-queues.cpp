class MyStack {
private:
    queue<int> quFir;
    queue<int> quSec;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        quFir.push(x);

        while(!quSec.empty()) {
            quFir.push(quSec.front());
            quSec.pop();
        }
        
        while(!quFir.empty()) {
            quSec.push(quFir.front());
            quFir.pop();
        }

    }
    
    int pop() {
        int result = quSec.front();
        quSec.pop();
        return result;
    }
    
    int top() {
        return quSec.front();
    }
    
    bool empty() {
        return quSec.empty();
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