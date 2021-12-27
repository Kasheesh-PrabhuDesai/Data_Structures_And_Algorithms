/*

Given a sorted array of integers and a target element. Return the index number of the target element 
if present in the array else return -1

Approach:

1) As the array is sorted, first compare the target element with the middle element of the array.
If the element is the same, return the middle index
2) If the target element is less than the middle element, than recursively check for the target element
only in the left half of the array. Follow the same method as done in 1)
3) If the target element is greater than the middle element, then recursively check for the target element
in the right half of the array following the same steps as above.
4) If target element is found, return its index else return -1.

Time Complexity: O(LogN) where N is the size of the sorted input array

Space Complexity: O(1) as no extra data structure is used

*/

#include <iostream>
#include <vector>

using namespace std;

void binary_search_recursive(vector<int>& arr, int targetValue, int startIdx,int endIdx)
{
    int middleIdx = (startIdx + endIdx)/2;

    if(targetValue==arr[middleIdx])
        cout<<"The target value lies at index no: "<<middleIdx<<endl;
    
    else if(targetValue>arr[middleIdx])
    {
        binary_search_recursive(arr,targetValue,middleIdx+1,endIdx);
    }
    else
    {
        binary_search_recursive(arr,targetValue,startIdx,middleIdx-1);
    }
}


int main()
{
    vector<int> arr = {10,11,12,13,14,15,16,18};
    int targetValue = 12;

    binary_search_recursive(arr,targetValue,0,arr.size()-1);
}