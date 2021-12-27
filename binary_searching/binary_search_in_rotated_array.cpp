/*

You have been given a sorted array/list ARR consisting of ‘N’ elements. You are also given an integer 
‘K’. Now the array is rotated at some pivot point unknown to you. For example, 
if ARR = [ 1, 3, 5, 7, 8]. Then after rotating ARR at index 3, the array will be 
ARR = [7, 8, 1, 3, 5].

Now, your task is to find the index at which ‘K’ is present in ARR.
Note :
1. If ‘K’ is not present in ARR then print -1.
2. There are no duplicate elements present in ARR. 
3. ARR can be rotated only in the right direction.
For example, if ARR = [12, 15, 18, 2, 4] and K = 2, then the position at which K is present in the 
array is 3 (0-indexed).

Approach:

Here is the algorithm:

We initialise two integer variables ‘si’ and ‘ei’ denoting the start index and the end index to 0 and
N -1, respectively. We also initialise another integer variable ‘pivot’ to 0 that stores the index 
of the pivot element. In the modified binary search, we will compare ARR[mid] with ARR[0] because 
if ARR[mid] < ARR[0], then it is guaranteed that ‘pivot’ is mid or present on its left side. Else, 
‘pivot’ is present on the right side. 

The modified binary search to find the pivot point:

1) We find the index of the middle element of ARR as mid = si + (ei - si) /2 .
2) If (ARR[mid] < ARR[0]) pivot = mid, We update the end index ei, ei = mid - 1.
3) Else We update the start index si, si = mid + 1.
 

After finding the pivot, we can easily locate the two sorted parts of ARR, one starting from 0 
to pivot - 1 and the other from pivot to N - 1. Now, we apply binary search in that sorted part 
of ARR in which the element K may lie. If K is present, we return its index. Else, we return -1.

Time Complexity: O(LogN) where N is the size of the array
Space Complexity: O(1)as no extra data structure is used
*/
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr,int startIdx,int endIdx,int targetValue)
{
    
    while(startIdx<=endIdx)
    {
	    int midIdx = (startIdx+endIdx)/2;
        
        if(arr[midIdx]==targetValue)
            return midIdx;
        
        else if(targetValue>arr[midIdx])
            startIdx=midIdx+1;
        else
            endIdx=midIdx-1;
        
        
    }

	return -1;
}

int findPosition(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
	int si = 0, ei = n - 1;

    int pivot = 0, index;

    while(si <= ei)
    {
        int mid = si + (ei - si) / 2;

        if(arr[mid] < arr[0])
        {
            pivot = mid;
            ei = mid - 1;
        }
        else
        {
            si = mid + 1;
        }
    }

    if(pivot == 0 || (k <= arr[n - 1] && k >= arr[pivot]))
    {
        index = binarySearch(arr, pivot, n - 1, k);
    }
    else
    {
        index = binarySearch(arr, 0, pivot - 1, k);
    }

    return index;
}

int main()
{
    vector<int>arr = {2,4,5,6,8,9,1};
    int n = arr.size();
    int targetValue = 9;

    cout<<findPosition(arr,n,targetValue)<<endl;


}


