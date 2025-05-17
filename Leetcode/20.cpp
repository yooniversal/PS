class Solution {
    public:
        char counter(char c) {
            if (c == ')') return '(';
            if (c == ']') return '[';
            return '{';
        }
    
        bool isValid(string s) {
            stack<char> st;
            
            for (int i=0; i<s.size(); i++) {
                if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                    if (st.empty()) return false;
                    if (st.top() != counter(s[i])) return false;
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
    
            if (!st.empty()) return false;
    
            return true;
        }
    };