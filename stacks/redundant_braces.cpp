#include <stack>
int Solution::braces(string A) {

    stack<char> st;
    bool redundant;
    for(char c:A)
    {
        if(c==')')
        {
            char top = st.top();
            st.pop();

            redundant = true;

            while(!st.empty() && top!='(')
            {
                if(top=='+' || top=='-' || top=='/' || top=='*')
                    redundant=false;
                
                top = st.top();
                st.pop();
            }

            if(redundant==true)
                return true;
        }
        else
            st.push(c);
    }

    return false;
}
