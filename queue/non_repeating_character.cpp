#include <iostream>
#include <queue>

using namespace std;

int firstNonRepeatingCharacter(string A) {
  // Write your code here.
	int charArray[26]={0};
	int result_index=-1;
	char ch;
	bool found=false;
	queue<char> q;
	
	for(int i=0;i<A.size();i++)
	{
		q.push(A[i]);
		charArray[A[i]-'a']++;
	}
	
	while(!q.empty())
	{
		if(charArray[q.front()-'a']>1)
		{
			q.pop();
		}
		else
		{
			ch = q.front();
			found=true;
			break;
		}
	}
	
	if(found)
		return A.find(ch);
	else
		return -1;
}

int main()
{
    cout<<firstNonRepeatingCharacter("abc")<<endl; //should output index of a i.e 0
}

