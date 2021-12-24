/*

Given a string s, return the maximum number of unique substrings that the given string 
can be split into. You can split string s into any list of non-empty substrings, 
where the concatenation of the substrings forms the original string. However, you must 
split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.

Approach:

1) Declare a hashmap to store the substrings generated at each iteration.
2) If the substring is not in the hashmap, add it to the hasmap and go to the next index
3) If the substring is present in the hashmap, then it is not unique. Continue added the
characters of the string until a unqiue substring is obtained.
4) If the string is traversed and the last elements are not unique, perform a backtracking
call until a unique substring is obtained,=.

Time Complexity: O(N) where N is the size of the string
Space Complexity: O(N) where N is the size of the string
*/

#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    unordered_map<string,int>us;
    int n;
    int ans=0;
    void backtrack(int i,string s,int res){
        //if the index value is more than then size of the string, the entire string has been processed and the ans is returned
        if(i>=n){
            ans=max(res,ans);
            return;
        }
        //iterate through the entire string recursively while performing backtracking calls
        for(int l=1;l<=n-i;l++){
            string d=s.substr(i,l);
            //check if the substring generated is unique by comparing it with the contents of the hashmap
            if(!us[d]){
            us[d]=1;
            backtrack(i+l,s,res+1);
            us[d]=0;
            }
            
        }
    }
    int maxUniqueSplit(string s) {
        n=s.size();
        backtrack(0,s,0);
        return ans;
    }
};


int main()
{
    Solution s;
    cout<<s.maxUniqueSplit("wwwzfvedwfvhsww")<<endl;

    return 0;
}



