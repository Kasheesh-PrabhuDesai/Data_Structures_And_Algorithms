#include <stack>
#include<queue>
#include<iostream>

using namespace std;

#include <stack>
queue<int> reverseElements(queue<int> q, int k)
{
    stack<int> s;
	
	for(int i=0;i<k;i++)
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<q.size()-k;i++)
    {
        q.push(q.front());
        q.pop();
    }
    
    return q;
    

}


int main()
{
    queue<int> a ,r;
    a.push(1);
    a.push(2);
    a.push(3);
    //a.push(4);
    //a.push(5);

    r = reverseElements(a,3);

    while(!r.empty())
    {
        cout<<r.front()<<endl;
        r.pop();
    }

}
