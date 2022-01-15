//https://www.geeksforgeeks.org/overlapping-subproblems-property-in-dynamic-programming-dp-1/
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
#define NIL -1// here NIL = -1
#define MAX 100//MAX =100
using namespace std;
int lookup[MAX];
void initialize()
{
    int i;
    for(i=0;i<MAX;i++)
    {
        lookup[i]=NIL;//lookup array with 100 as max length
                      // initializing all to -1
    }
}
int nth_fibonaci(int n)
{
    if(lookup[n]==NIL)
    {
        if(n<=1)
        {
         lookup[n]=n;//if n== 0 then f(0)=0 or f(1)=0+1 that is 1
        }
        else 
        {
            cout<<"n         = "<<n<<endl;
            cout<<"lookup[n] = "<<lookup[n]<<endl;
            
            lookup[n]=nth_fibonaci(n-1)+nth_fibonaci(n-2);
            
        }
    }
    cout<<" ----------------------"<<endl;
    cout<<"n         = "<<n<<endl;
    cout<<"lookup[n] = "<<lookup[n]<<endl;
    cout<<" ----------------------"<<endl;
    return lookup[n];
}
int main() 
{
    int n=5; 
    initialize();
    cout<<nth_fibonaci(n);

    return 0;
}
/*OUTPUT :

INITIALLY  lookup : 0  1  2  3  4  5
                   -1 -1 -1 -1 -1 -1
SO lookup[5]=-1
THEN lookup[5]=FIBO(4)+FIBO(3)
AGAIN CALLED 
lookup[4]=-1
THEN lookup[4]=FIBO(3)+FIBO(2)
.
.
.

NOW lookup[2]=FIBO(1)+FIBO(0);
lookup[1]=1;RETURNED
FIBO(0) CALLED
AND lookup[0]=0 RETURNED 
----------------------

n         = 5
lookup[n] = -1
n         = 4
lookup[n] = -1
n         = 3
lookup[n] = -1
n         = 2
lookup[n] = -1
 ----------------------
n         = 1
lookup[n] = 1
 ----------------------
 ----------------------
n         = 0
lookup[n] = 0
 ----------------------
 ----------------------
n         = 2
lookup[n] = 1
 ----------------------
 ----------------------
n         = 1
lookup[n] = 1
 ----------------------
 ----------------------
n         = 3
lookup[n] = 2
 ----------------------
 ----------------------
n         = 2
lookup[n] = 1
 ----------------------
 ----------------------
n         = 4
lookup[n] = 3
 ----------------------
 ----------------------
n         = 3
lookup[n] = 2
 ----------------------
 ----------------------
n         = 5
lookup[n] = 5
 ----------------------
5
*/
