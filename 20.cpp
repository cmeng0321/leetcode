/*
20. Valid Parentheses

	Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

	An input string is valid if:

		Open brackets must be closed by the same type of brackets.
		Open brackets must be closed in the correct order.
	Note that an empty string is also considered valid.

	Example 1:
	Input: "()"
	Output: true
	
	Example 2:
	Input: "()[]{}"
	Output: true

	Example 3:
	Input: "(]"
	Output: false

	Example 4:
	Input: "([)]"
	Output: false
	
	Example 5:
	Input: "{[]}"
	Output: true
*/ 

class Solution {
public:
    bool isValid(string s) {
        
        if(s.size() == 0) return true;
        
        stack<char> st;
        int i;
        
        for (i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else {
                if (st.empty()) return false;
                if (s[i] == ')' && st.top() != '(') return false;
                if (s[i] == ']' && st.top() != '[') return false;
                if (s[i] == '}' && st.top() != '{') return false;
                st.pop();
            }
        } 
        return st.empty();
    }
};
