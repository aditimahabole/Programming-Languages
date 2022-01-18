
//https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
//MEMOIZATION USED TOP/BOTTOM APPROACH
int dp[20];
void initialize()
{
    for(int i=0;i<20;i++)
    {
        dp[i]=-1;
    }
}
int fib(int n)
{
    if(n<=1)
    {
        return n;
    }
    int _1st=0,_2nd=0;
    if(dp[n - 1]!=-1)
    {
        _1st=dp[n - 1];
        cout<<"____________________"<<endl;
        cout<<"inside if 1"<<endl;
        cout<<"n     = "<<n<<endl;
        cout<<"n - 1 = "<<n - 1<<endl;
        cout<<"1st   = "<<_1st<<endl;
        cout<<"____________________"<<endl;
    }
    else 
    {
        cout<<"___________________"<<endl;
        cout<<"else 1 run"<<endl;
        cout<<"1st = "<<_1st<<endl;
        cout<<"___________________"<<endl;
        
        _1st=fib(n - 1);
        cout<<"________________________"<<endl;
        cout<<"fib(n-1) calling stopped"<<endl;
        cout<<"________________________"<<endl;
    }
    if(dp[n - 2]!=-1)
    {
        _2nd = dp[n - 2];
        cout<<"____________________"<<endl;
        cout<<"inside if 2"<<endl;
        cout<<"n     = "<<n<<endl;
        cout<<"n - 2 = "<<n - 2<<endl;
        cout<<"2nd   = "<<_2nd<<endl;
        cout<<"____________________"<<endl;
    }
    else 
    {
        cout<<"___________________"<<endl;
        cout<<"else 2 run"<<endl;
        cout<<"2nd = "<<_2nd<<endl;
        cout<<"___________________"<<endl;
    }
    cout<<"________________"<<endl;
    cout<<"FINAL ANS "<<endl;
    cout<<"1st   = "<<_1st<<endl;
    cout<<"2nd   = "<<_2nd<<endl;
    cout<<"dp["<<n<<"] = "<<_1st + _2nd<<endl;
    
    cout<<"________________"<<endl;
    
    
    
    return dp[n]=_1st + _2nd;
 }
int main() 
{
    int num=4;
    initialize();
    cout<<fib(num + 1);
    return 0;
}
/*OUTPUT : 

___________________
else 1 run
1st = 0
___________________
___________________
else 1 run
1st = 0
___________________
___________________
else 1 run
1st = 0
___________________
___________________
else 1 run
1st = 0
___________________
________________________
fib(n-1) calling stopped
________________________
___________________
else 2 run
2nd = 0
___________________
________________
FINAL ANS 
1st   = 1
2nd   = 0
dp[2] = 1
________________
________________________
fib(n-1) calling stopped
________________________
___________________
else 2 run
2nd = 0
___________________
________________
FINAL ANS 
1st   = 1
2nd   = 0
dp[3] = 1
________________
________________________
fib(n-1) calling stopped
________________________
____________________
inside if 2
n     = 4
n - 2 = 2
2nd   = 1
____________________
________________
FINAL ANS 
1st   = 1
2nd   = 1
dp[4] = 2
________________
________________________
fib(n-1) calling stopped
________________________
____________________
inside if 2
n     = 5
n - 2 = 3
2nd   = 1
____________________
________________
FINAL ANS 
1st   = 2
2nd   = 1
dp[5] = 3
________________
3
*/
