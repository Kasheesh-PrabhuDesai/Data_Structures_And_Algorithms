#include<iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque<int> dq;
        vector<int> res;
        for (int i=0; i<nums.size(); i++){

            // base case for first element
            if (dq.empty()){
                dq.push_back(i);
            }

            // remove elements outside the current window
            if (dq.front() <= (i - k)){
                dq.pop_front();
            }

            // move max element to the front
            while (!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);

            // print out only when the first window is completed
            if (i >= (k - 1)){
                res.push_back(nums[dq.front()]);
            }    

        }
        
        return res;
    }
};