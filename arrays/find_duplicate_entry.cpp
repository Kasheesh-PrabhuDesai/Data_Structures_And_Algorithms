/*

Given an integer array nums, return true if any value appears at least twice in the 
array, and return false if every element is distinct.

Aproach:

There are two aproaches which can be used to solve this problem.

1) Sort the vector. Run a for loop to iterate through the entire sorted array to check 
for any duplicate values.

Time Complexity: O(NLogN) where N is the size of the array
Space Complexity: O(1) As no extra space is required 

2) USe a hash table to store the count of each integer number in the array.
If the count is more than 1 then return true else continue iterating through the array.

Time Complexity: O(N) where N is the size of the array
Space Complexity: O(N) where N is the size of the array

*/

#include <map>
#include <vector>
#include<iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool containsDuplicateusingHashing(vector<int>& nums) {
        
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
                m[nums[i]] = 1;
            else
            {
                return true;
            }
        }
        return false;
    }

    static bool containsDuplicateusingSorting(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[i])
                return true;
        }
        return false;
        
        
    }
};


int main()
{
    vector<int> nums = {1,2,3,4,5,1};

    cout<<Solution::containsDuplicateusingSorting(nums)<<endl;
    cout<<Solution::containsDuplicateusingHashing(nums)<<endl;
}