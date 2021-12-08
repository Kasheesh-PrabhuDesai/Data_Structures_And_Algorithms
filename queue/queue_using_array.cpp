/* implement a queue using an array data structure */

#include <iostream>
#define n 5
using namespace std;

class Queue
{
    int* ptr;
    int front,rear;
    public:

    Queue()
    {
        ptr = new int[n];
        front=-1;
        rear=-1;
    }

    void push(int val)
    {
        if(rear>n)
            cout<<"Queue overflow"<<endl;
        
        else if(front==-1)
            front++;

        rear++;
        ptr[rear] = val;
        
    }

    void peek()
    {
        if(rear==-1 || front==-1)
            cout<<"Queue is Empty"<<endl;
        
        cout<<"Element at front of queue is: "<<ptr[front]<<endl;
    }

    int pop()
    {
        if(front>rear || front==-1)
            cout<<"Empty Queue"<<endl;
        
        int val = ptr[front];
        front++;

        return val;
    }

    void isEmpty()
    {
        if(front==-1 || front>rear || rear==-1)
            cout<<"Queue is empty"<<endl;
        else
            cout<<"Queue is not empty"<<endl;
    }
};


int main()
{
    Queue q;
    q.push(2);
    q.push(5);
    cout<<"Element removed from queue is: "<< q.pop()<<endl;
    q.peek();
    q.isEmpty();
}