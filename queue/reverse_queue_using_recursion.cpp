#include <iostream>
#include <queue> 
using namespace std;

queue<int> reverseQueue(queue<int> q)
{
    if(q.empty())
        return q;
    
    int val = q.front();
    q.pop();
    q = reverseQueue(q);
    q.push(val);
    
    return q;
    
    
}

int main()
{
    
    queue<int> a;
    a.push(10);
    a.push(6);
    a.push(3);
    a.push(7);
    
    queue<int> ans = reverseQueue(a);
    
    while(!ans.empty())
    {
        cout<<ans.front()<<endl;
        ans.pop();
    }


    return 0;
}
