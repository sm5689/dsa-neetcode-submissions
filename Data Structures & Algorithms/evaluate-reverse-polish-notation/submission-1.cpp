class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for (string s : tokens) {
            if (s == "+" ) {
                int top = stoi(st.top());
                st.pop();
                string newTop = to_string(stoi(st.top())+top);
                st.pop();
                st.push(newTop);
            }
            else if (s == "-" ) {
                int top = stoi(st.top());
                st.pop();
                string newTop = to_string(stoi(st.top())-top);
                st.pop();
                st.push(newTop);
            }
            else if (s == "*") {
                int top = stoi(st.top());
                st.pop();
                string newTop = to_string(stoi(st.top())*top);
                st.pop();
                st.push(newTop);
            }
            else if (s == "/") {
                int top = stoi(st.top());
                st.pop();
                string newTop = to_string(stoi(st.top())/top);
                st.pop();
                st.push(newTop);
            }
            else {
                st.push(s);            
            }
        }
        return stoi(st.top());
    }
};
