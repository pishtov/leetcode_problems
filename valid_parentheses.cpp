/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

Example 5:
Input: s = "([)]"
Output: false
 
Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

// 3ms runtime
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
     
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
                continue;
            }
         
            if (st.empty() || st.top() != pairs[c]) {
                return false;
            }
            st.pop();
        }
        return st.empty();
    }
};

// 0ms runtime
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

/* Valid Parentheses — Approach
The main idea is to use a stack.
A stack is useful here because brackets need to be closed in the reverse order that they were opened.
For example:
([])
We first open (, then [. The [ must be closed before the (, so we need to remember the most recently opened bracket.
That's exactly what a stack does: the last thing we put in is the first thing we take out.
We go through the string from left to right.
When we see an opening bracket:
(, [, {
we put it into the stack.
When we see a closing bracket:
), ], }
we check the top of the stack.
If the top is the matching opening bracket, we remove it from the stack.
For example:
([])
( → put ( in the stack
[ → put [ in the stack
] → top is [, so they match → remove [
) → top is (, so they match → remove (
The stack is now empty, so the string is valid.
If the brackets don't match, we immediately return false.
For example:
([)]
( → stack: (
[ → stack: ([
) → the top is [, but ) needs (
So the order is wrong → false.
We also have to check whether the stack is empty when we encounter a closing bracket. If it is empty, there is nothing for that bracket to close, so the string is invalid.
Finally, after going through the entire string, the stack must be empty. If something is still inside it, there are opening brackets that were never closed.
So the overall approach is:
Opening bracket → put it on the stack.
Closing bracket → check whether it matches the most recently opened bracket, then remove it.
At the end → stack must be empty.
The two versions use the same approach. The first uses a map to associate each closing bracket with its matching opening bracket, while the second checks the possible pairs directly.
Time: O(n), because we go through the string once.
Space: O(n) in the worst case, because the stack could contain all the characters if they are all opening brackets. */
