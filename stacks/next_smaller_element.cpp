
vector<int> Solution::prevSmaller(vector<int> &A) {
    if(A.size()==0) return A;
    vector<int> ans;
    stack<int> st;
    ans.push_back(-1);
    st.push(A[0]);

    for(int i=1;i<A.size();i++)
    {
        if(A[i]>st.top())
        {
            ans.push_back(st.top());
            st.push(A[i]);
        }
        else
        {
            while(!st.empty() && A[i]<=st.top())
            {
                st.pop();
            }
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());
            st.push(A[i]);
        }
    }
    
    return ans;
}