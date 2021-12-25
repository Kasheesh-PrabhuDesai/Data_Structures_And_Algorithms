/*

You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list 
of all pairs of elements such that each sum of elements of each pair equals 'S'.

Note:
Each pair should be sorted i.e the first value should be less than or equals to the second value.
Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs 
have the same first value, the pair with a smaller second value should come first.

Approach:

Brute Force

1) First sort the array using the inbuilt sort method
2) Use two pointer technique. Initialise "start" pointer to start of array and "end" to end of array.
3) Using two nested loops , iterate through each element of array. if element at start index + element
at end index add up to the required sum, add the pair to the resultant vector array.

Time Complexity: O(NLogN) as sorting takes LogN where N is the size of the input array
Space complexity: O(N) where N is the size of the input array

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    int startPtr=0;
    int endPtr = arr.size()-1;
    
    sort(arr.begin(),arr.end());
    
    vector<vector<int>> pairs;
    
    while(startPtr<endPtr)
    {
        while(startPtr<endPtr)
        {
            if(arr[startPtr]+arr[endPtr]==s)
            {
                pairs.push_back({arr[startPtr],arr[endPtr]});
            }
            endPtr--;
        }
        startPtr+=1;
        endPtr=arr.size()-1;
        	    
    }
    
    return pairs;
}

int main()
{
    vector<int> arr = {2,-3,3,3,-2};
    vector<vector<int>> res = pairSum(arr,0);
    
    for(auto i:res)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
