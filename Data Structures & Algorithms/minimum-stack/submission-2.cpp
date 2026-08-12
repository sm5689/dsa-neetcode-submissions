class MinStack {
public:
    stack<int> st;
    stack<int> miniSt;

    MinStack() {
        
    } 
    
    void push(int val) {
        st.push(val);
        if (miniSt.empty()) miniSt.push(val);
        else if (val < miniSt.top()) miniSt.push(val);
        else miniSt.push(miniSt.top());
    }
    
    void pop() {
        st.pop();
        miniSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return miniSt.empty()?0:miniSt.top();
    }
};
