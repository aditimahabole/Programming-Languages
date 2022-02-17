
/////////////TOWER OF HANOI///////////////////
#include <iostream>
using namespace std;
void tower_of_hanoi(int n,char from ,char to,char via)
{
    if(n==0)
    {
        return;
    }
    tower_of_hanoi(n-1,from,via,to );
    cout<<"Move Disk "<<n<<" From rod "<<from<<" To rod "<<to<<endl;
    tower_of_hanoi(n-1,via,to,from );
}

int main() 
{
    int n=4;
    tower_of_hanoi(n,'A','C','B');
    return 0;
}
/*
Move Disk 1 From rod A To rod B
Move Disk 2 From rod A To rod C
Move Disk 1 From rod B To rod C
Move Disk 3 From rod A To rod B
Move Disk 1 From rod C To rod A
Move Disk 2 From rod C To rod B
Move Disk 1 From rod A To rod B
Move Disk 4 From rod A To rod C
Move Disk 1 From rod B To rod C
Move Disk 2 From rod B To rod A
Move Disk 1 From rod C To rod A
Move Disk 3 From rod B To rod C
Move Disk 1 From rod A To rod B
Move Disk 2 From rod A To rod C
Move Disk 1 From rod B To rod C
*/
///////////FIBONACII/////////////////////////////

#include<bits/stdc++.h>
using namespace std;
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}
int main ()
{
    int n = 5;
    cout <<fib(n);
    return 0;
}
