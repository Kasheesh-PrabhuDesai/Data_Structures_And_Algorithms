/*

Given an array of integers nums and an integer target, return indices of the two numbers
such that they add up to target. You may assume that each input would have exactly one 
solution, and you may not use the same element twice. You can return the answer in any 
order.

Approach:

Using two pointers, iterate through the entire vector array while checking if the values
in the vector array at the pointers equals the target sum. If yes return the indices.

Time Complexity: O(N2) where N is the size of the vector array
Space Complexity: O(1) as no extra data structre is used

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> result;
         
        for(int firstPtr=0;firstPtr<nums.size()-1;firstPtr++)
        {
            for(int secondPtr=firstPtr+1;secondPtr<nums.size();secondPtr++)
            {
                int sum = nums[firstPtr]+nums[secondPtr];
                if(sum==target)
                {
                    result= {firstPtr,secondPtr};
                    break;
                }
            }
            if(result.size()>0)
                break;
        }
        
        return result;
        
    }
};

int main()
{
    vector<int> nums = {2,7,1,12};
    int target = 9;

    vector<int> result = Solution::twoSum(nums,target);

    for(int i:result)
        cout<<i<<" ";
    
    return 0;
}