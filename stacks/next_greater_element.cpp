#include <vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> array) {
  // Write your code here.
	vector<int> result={};
	stack<int> st;
	bool found=false;
	int n=array.size();
	for(int i=0;i<n;i++)
	{
		st.push(array[i]);
		for(int j=i+1;j<n+i;j++)
		{
			if(array[j%n]>st.top())
			{
				st.pop();
				result.push_back(array[j%n]);
				found=true;
				break;
			}
			else
				found=false;
		}
		if(found==false)
		{
			result.push_back(-1);
			st.pop();
		}
		
	}
  return result;
}
