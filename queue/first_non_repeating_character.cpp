#include <iostream>
#include<queue>

using namespace std;

string firstNonRepeatingCharacter(string A)  {
    queue<char> q;
    string result="";
    int charArr[26]={0};

    for(int i=0;i<A.size();i++)
    {
        q.push(A[i]);
        charArr[A[i]-'a']+=1;

        while(!q.empty())
        {
            if(charArr[q.front()-'a']>1)
            {
                q.pop();
            }
            else
            {
                result.push_back(q.front());
                break;
            }
        }

        if(q.empty())
        {
            result.push_back('#');
        }

    }

    return result;
}

int main()
{
    cout<<firstNonRepeatingCharacter("abcdcaf")<<endl;

    return 0;
}
