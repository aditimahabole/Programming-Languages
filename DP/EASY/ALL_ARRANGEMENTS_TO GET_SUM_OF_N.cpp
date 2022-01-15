/*Given 3 numbers {1, 3, 5}, we need to tell
the total number of ways we can form a number 'N' 
using the sum of the given three numbers.
(allowing repetitions and different arrangements).

Total number of ways to form 6 is: 8
1+1+1+1+1+1
1+1+1+3
1+1+3+1
1+3+1+1
3+1+1+1
3+3
1+5
5+1
*/
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
////////////////////THIS IS RECURSSIVE METHOD ///////////
int arrangements(int n)
{
  if(n<0)
  {
      return 0;
  }
  if(n==0)
  {
      return 1;
  }
  return arrangements(n-1)+arrangements(n-3)+arrangements(n-5);
  //we are basically returning the count 
}
int main() 
{
    int n=4; 
    // here {1,3,5} are gigven as numbers
    cout<<arrangements(n);
    // like n=4
    // so possible arrange ments are 3:
    // 1+1+1+1
    // 1+3
    // 3+1
    return 0;
}
///////////////////////////////////////////////////////

// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int dp[MAX];
////////////////////ADDING MEMOIZATION TO IT//////////////
void initialise()
{
    for(int i=0;i<MAX;i++)
    {
        dp[i]=-1;
    }
}
int arrangements(int n)
{
  if(n<0)
  {
      return 0;
  }
  if(n==0)
  {
      return 1;
  }
  if(dp[n]!=-1)
  {
      return dp[n];
  }
  return dp[n]=arrangements(n-1)+arrangements(n-3)+arrangements(n-5);
  //we are basically returning the count 
}
int main() 
{
    int n=4; 
    // here {1,3,5} are gigven as numbers
    initialise();
    cout<<arrangements(n);
    // like n=4
    // so possible arrange ments are 3:
    // 1+1+1+1
    // 1+3
    // 3+1
    return 0;
}
////////////////////////////////////////////////////

////////////////////TABULATION METHOD//////////////////
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arrangements(int n)
{
int  f[n+1];
 f[1]=1;//ways 
 f[2]=1;
 f[3]=1;
 f[4]=3;
 f[5]=5;
 int i;
 for(i=6;i<=n;i++)
 {
     if(i-1<0)
     {
         f[i-1]=0;
     }
     if(i-1==0)
     {
         f[i-1]=1;
     }
     if(i-3<0)
     {
     f[i-3]=0;
     }
      if(i-3==0)
     {
         f[i-3]=1;
     }
     if(i-5<0)
     {
     f[i-5]=0;
     }
      if(i-5==0)
     {
         f[i-5]=1;
     }
     f[i]=f[i-1]+f[i-3]+f[i-5];
 }
 return f[n]+1;
}
int main() 
{
    int n=6; 
    // here {1,3,5} are gigven as numbers
    cout<<arrangements(n);
  
    return 0;
}
