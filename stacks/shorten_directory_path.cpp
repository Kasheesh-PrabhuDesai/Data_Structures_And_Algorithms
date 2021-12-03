string Solution::simplifyPath(string A) {
    string result="";
	stack<string> s;
	string dir="";
    int n = A.size();
    result.append("/");
	for(int i=0;i<n;i++)
	{
	    dir.clear();
        while(A[i]=='/')
            i++;
        
        while(i<n && A[i]!='/')
        {
            dir.push_back(A[i]);
            i++;
        }
        if(dir.compare("..")==0)
        {
            if(!s.empty())
                s.pop();
        }
        else if(dir.compare(".")==0)
            continue;
        
        else if(dir.size()!=0)
            s.push(dir);
	}
		
	
    stack<string> st1;
    while (!s.empty()) {
        st1.push(s.top());
        s.pop();
    }
  
    while (!st1.empty()) {
        string temp = st1.top();
         
        // if it's the last element no need
        // to append "/"
        if (st1.size() != 1)
            result.append(temp + "/");
        else
            result.append(temp);
 
        st1.pop();
    }
	
    return result;


}