class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (int i = 0; i < s.length(); i++) {
        char c = s[i];
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }
            if ( c == ')' && st.top() == '(' || c == ']' && st.top() == '[' || c == '}' && st.top() == '{' ) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}
};
