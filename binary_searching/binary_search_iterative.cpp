/*

Given a sorted array of integers and a target element. Return the index number of the target element 
if present in the array else return -1

Approach:

1) Start by initialising three pointers. startIdx,middleIdx and endIdx. 
2) Compare target value with value at the middleIdx. If same return the middleIdx.
3) If target value is less than the value at the middleIdx, decrement the middleIdx by 1 and search
again.
4) If target value is greater than the value at the middleIx, increment the middleIdx by 1 and search
again.
5) If the target value is found, return its index else return -1.

Time Complexity: O(LogN) where N is the size of the sorted input array

Space Complexity: O(1) as no extra data structure is used

*/

#include <iostream>
#include <vector>

using namespace std;

void binary_search_iterative(vector<int>& arr, int targetValue, int startIdx,int endIdx)
{
    

    while(startIdx<=endIdx)
    {
        int middleIdx = (startIdx + endIdx)/2;

        if(arr[middleIdx]==targetValue)
        {
            cout<<"The target value lies at index: "<<middleIdx<<endl;
            break;
        }
        
        else if(targetValue<arr[middleIdx])
        {
            endIdx = middleIdx-1;
        }
        
        else
        {
            startIdx = middleIdx+1;
        }
    }

}


int main()
{
    vector<int> arr = {10,11,12,13,14,15,16,18};
    int targetValue = 12;

    binary_search_iterative(arr,targetValue,0,arr.size()-1);
}