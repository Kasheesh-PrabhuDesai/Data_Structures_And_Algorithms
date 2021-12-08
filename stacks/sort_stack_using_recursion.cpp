#include <iostream>
#include <stack>
using namespace std;
void sortInsert(stack<int>& stack,int elem)
{
    if(stack.empty() || stack.top()<=elem)
    {
        stack.push(elem);
    	return;
    }
   	
    int top = stack.top();
    stack.pop();
    sortInsert(stack,elem);
    stack.push(top);
}


void sortStack(stack<int> &stack)
{
	if(stack.empty())
        return;
   	
    int val = stack.top();
    stack.pop();
    sortStack(stack);
    
    sortInsert(stack,val);
    
}
int main()
{
    stack<int> a;
    a.push(5);
    a.push(-2);
    a.push(9);
    a.push(-7);
    a.push(3);
    
    sortStack(a);
    
    while(!a.empty())
    {
        cout<<a.top()<<endl;
        a.pop();
    }
    
}
