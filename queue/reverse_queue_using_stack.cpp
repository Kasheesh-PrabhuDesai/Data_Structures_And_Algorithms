#include <iostream>
#include <queue>
#include <stack>

using namespace std;

queue<int> reverseQueue(queue<int> q)
{
    stack<int> s;

    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    return q;
}

int main()
{
    queue<int> a,ans;
    a.push(10);
    a.push(6);
    a.push(8);
    a.push(12);
    a.push(3);

    ans = reverseQueue(a);

    while(!ans.empty())
    {
        cout<<ans.front()<<endl;
        ans.pop();
    }

    return 0;
}