class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto & s : tokens) {
            if(s == "*") {
                int i = st.top(); st.pop();
                int j = st.top(); st.pop();
                st.push(i * j);
            }
            else if(s == "+") {
                int i = st.top(); st.pop();
                int j = st.top(); st.pop();
                st.push(i + j);
            }
            else if(s == "/") {
                int i = st.top(); st.pop();
                int j = st.top(); st.pop();
                st.push(j / i);
            }
            else if(s == "-") {
                int i = st.top(); st.pop();
                int j = st.top(); st.pop();
                st.push(j - i);
            }
            else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
