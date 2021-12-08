/* 
When using recursion, the number of calls you make can grow exponentially. This in turn
increases the total time complexity of the algorithm. In order to reduce this time complexity
dynamic porgramming is used. In this example, a simple case of finding the nth fibonacci number
is considered. As the value of n increases a simple recursion call can take up to 2^n time to
compute the answer. The solution is to use a sort of a hash table with the key as the number n 
and the value as the fibonacci value of the nth number. This method is called memoization.
*/

//#################################################################################//

#include <iostream>
using namespace std;

long long find_fibonaci(long long n)
{
    long long lookup[n+2];
    lookup[0]=1;
    lookup[1]=1;
    for(int i=2;i<=n;i++)
    {
        lookup[i] = lookup[i-1] + lookup[i-2];
    }

    return lookup[n];

}

int main()
{

    cout<<find_fibonaci(100)<<endl;

    return 0;
}