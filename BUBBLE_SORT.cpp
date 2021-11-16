#include <iostream>

using namespace std;
void swap(int *a,int *b) // HERE WE USE * BEACUSE IN FUNTION WE PASSED ADDRESS SO NOW IF WE WANT TO FETCH THE VALUE INSIDE IT
                                             // WE USE * SO (*&arr[j] )WILL GIVE THE VALUE INSIDE IT FOR EXAPLE 1 2 3 WHATEVER WE STORED
                                            // & DENOTES THE ADDRESS WHICH CAN BE IN FORM 200455 WHATEVER AND * KILLS & AND GIVES ITS TRUE VALUE
                                            //SO &arr[j]= 2255000 (address)  AND *&arr[J]=4(value)
{
    int *temp;
    *temp=*a;
    *a=*b;
    *b=*temp;
}

int bubble_sort(int arr[],int n)
{
   // cout<<"INSIDE BUBBLE SORT FUNTION "<<endl;
    int i,j;
    int swap_count=0;
    for( i=0;i<n-1;i++)
    {
       //cout<<i<<"   value of i  :  \n";
        for(j=0;j<n-i-1;j++)
        {
           // cout<<j<<"   value of j :  \n";
            if(arr[j]>arr[j+1])
            {
                //cout<<"Values to be swapped  :  "<<arr[j]<<"  and  "<<arr[j+1]<<endl;
                swap(&arr[j],&arr[j+1]); //HERE WE ARE PASSING THE ADDRESS OF BOTH SO THAT CHNAGES CAN BE MADE
                swap_count++;                                            // THIS IS CALLED PASS BY REFRENCE
            }
        }
    }
   // cout<<"value of i and j  :  "<<i<<"   "<<j<<endl;
    return swap_count;
}
/*
IN BUBBLE SORT WE TRAVEL AND IF THE PREVIOUS ELEMENT IS GREATER THAN THE NEXT WE JUST SWAP AND BY THIS
THE LARGEST ELEMENT GOES TO THE LAST
WE DO SAME THING AGAIN BUT NOW ARRAY TRAVERSAL IS SHORTED
WE GO TILL n-2 BECAUSE LAST ELEMENT IS THE LARGEST WE  KNOW THEN WHY TO TRAVERSE THAT PART
EXAPME : 0 1 2 3 4
INDEX  : 0 1 2 3 4
FIRST LOOP IS FROM  INDEX 0 TO 3 ....WHY? BECAUSE WE HAVE TO SWAP THAT ELEMNT AND NEXT TO IT
SO IF LOOP RUNS FROM 0 TO 4 THEN LAST EMENT WILL BE SWAPPED WITH WHOM ....THERE IS NO ELEMENT AFTER 4TH INDEX NO 5TH INDEX EXIST
SO KEEP THIS IN MIND

NOW SECOND LOOP IS FROM
0 TO n-i-1
SO i=0     TO i=5-0-1  HERE n =5 AS 5 ELEMENTS
 i        TO     i
 0               4
 0               3
 0               2
 0               1
 AS 0 < 5-4-1 = 0<0 THIS CONDITION FAILS SO LOOP STOPS HERE THAT IS THE SECOND LOOP

*/
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
}

int main()
{
    int n;
   cout<<"ENTER SIZE : "<<endl;
   cin>>n;
   int arr[n];
   cout<<"ENTER ELEMENTS : "<<endl;
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   cout<<endl;
     cout<<"ORIGINAL ARRY :  "<<endl;
     for(int i=0;i<n;i++)
   {
       cout<<arr[i]<<"   ";
   }
    cout<<endl;
   cout<<"BUBBLE SORT CALLED  :  "<<endl;
   int count=bubble_sort(arr,n);
   cout<<"PRINT FUNTION CALLED "<<endl;
   print(arr,n);
    cout<<"TOTAL SWAP COUNTS  :  "<<count<<endl;
   cout<<"FUNTION COMPLETED "<<endl;
    return 0;
}
