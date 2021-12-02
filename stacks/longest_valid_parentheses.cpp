#include<stack>

class Solution {
public:
    stack<int> st;
    int valid_length;
    int longestValidParentheses(string s) {
        valid_length=0;
        st.push(-1);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                {
                    valid_length = max(valid_length,(i-st.top()));
                }
                    

            }
        }
        
        return valid_length;
        
    }
};