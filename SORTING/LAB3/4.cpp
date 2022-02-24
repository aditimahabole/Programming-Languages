
#include <iostream>
using namespace std;
void insertion_sort(int arr[],int low,int n)
{
    for(int i=low+1;i<n+1;i++)
    {
        int val=arr[i];
        cout<<"val = "<<val<<endl;
        int j=i;
        cout<<"j=i= "<<j<<endl;
        
        while(j>low && arr[j - 1]>val)
        {
            arr[j]=arr[j - 1];
            j--;
        }
        cout<<"early arr["<<j<<"] = "<<arr[j]<<endl;
        
        arr[j]=val;
        cout<<"after arr["<<j<<"] = "<<arr[j]<<endl;
    }
    cout<<"--INSERTION SORT END--"<<endl;
}
int partition(int arr[],int low,int high)
{
    cout<<"--PARTITION STARTED--"<<endl;
    int pi=arr[high];
    cout<<"pi = "<<pi<<endl;
    int i,j;
    i=low;
    j=low;
    for(int i=low;i<high;i++)
    {
        cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
        if(arr[i]<pi)
        {
            cout<<arr[i]<<" , "<<arr[j]<<"swapped "<<endl;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            j++;
            cout<<"j = "<<j<<endl;
        }
    }
    cout<<arr[high]<<" , "<<arr[j]<<"swapped "<<endl;
    int temp =arr[j];
    arr[j]=arr[high];
    arr[high]=temp;
    return j;
}
void hybrid_quick_sort(int *arr,int low,int high)
{
    while(low<high)
    {
        if(high-low +1<10)
        {
            cout<<"INSERTION_SORT CALLED "<<endl;
            insertion_sort(arr,low,high);
            break;
        }
        else 
        {
            cout<<"PARTITION HAPPENED "<<endl;
            int pi=partition(arr,low,high);
            if(pi-low<high-pi)
            {
                hybrid_quick_sort(arr,low,pi - 1);
                low= pi + 1;
                cout<<"low = "<<low<<endl;
            }
            else 
            {
                hybrid_quick_sort(arr,pi + 1,high);
                high= pi -1;
                cout<<"high = "<<high<<endl;
                
                
            }
        }
    }
}
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main() {
//     int arr[]={24,97,40,67,88,85,15,66,53,44,26,48,16,52,
//   45,23,90,18,49,80,23};
  int arr[]={20,1,4,2,3,5,18,19,12,6,7,10,8,15,9,11,13,16,14,17};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
   hybrid_quick_sort(arr,0,n-1);
   display(arr,n);

    return 0;
}
/*
/tmp/2RBRuZHBa4.o
20 1 4 2 3 5 18 19 12 6 7 10 8 15 9 11 13 16 14 17 
PARTITION HAPPENED 
--PARTITION STARTED--
pi = 17
arr[0] = 20
arr[1] = 1
1 , 20swapped 
j = 1
arr[2] = 4
4 , 20swapped 
j = 2
arr[3] = 2
2 , 20swapped 
j = 3
arr[4] = 3
3 , 20swapped 
j = 4
arr[5] = 5
5 , 20swapped 
j = 5
arr[6] = 18
arr[7] = 19
arr[8] = 12
12 , 20swapped 
j = 6
arr[9] = 6
6 , 18swapped 
j = 7
arr[10] = 7
7 , 19swapped 
j = 8
arr[11] = 10
10 , 20swapped 
j = 9
arr[12] = 8
8 , 18swapped 
j = 10
arr[13] = 15
15 , 19swapped 
j = 11
arr[14] = 9
9 , 20swapped 
j = 12
arr[15] = 11
11 , 18swapped 
j = 13
arr[16] = 13
13 , 19swapped 
j = 14
arr[17] = 16
16 , 20swapped 
j = 15
arr[18] = 14
14 , 18swapped 
j = 16
17 , 19swapped 
INSERTION_SORT CALLED 
val = 18
j=i= 18
early arr[17] = 20
after arr[17] = 18
val = 19
j=i= 19
early arr[18] = 20
after arr[18] = 19
--INSERTION SORT END--
high = 15
PARTITION HAPPENED 
--PARTITION STARTED--
pi = 14
arr[0] = 1
1 , 1swapped 
j = 1
arr[1] = 4
4 , 4swapped 
j = 2
arr[2] = 2
2 , 2swapped 
j = 3
arr[3] = 3
3 , 3swapped 
j = 4
arr[4] = 5
5 , 5swapped 
j = 5
arr[5] = 12
12 , 12swapped 
j = 6
arr[6] = 6
6 , 6swapped 
j = 7
arr[7] = 7
7 , 7swapped 
j = 8
arr[8] = 10
10 , 10swapped 
j = 9
arr[9] = 8
8 , 8swapped 
j = 10
arr[10] = 15
arr[11] = 9
9 , 15swapped 
j = 11
arr[12] = 11
11 , 15swapped 
j = 12
arr[13] = 13
13 , 15swapped 
j = 13
arr[14] = 16
14 , 15swapped 
INSERTION_SORT CALLED 
val = 15
j=i= 15
early arr[14] = 16
after arr[14] = 15
--INSERTION SORT END--
high = 12
PARTITION HAPPENED 
--PARTITION STARTED--
pi = 13
arr[0] = 1
1 , 1swapped 
j = 1
arr[1] = 4
4 , 4swapped 
j = 2
arr[2] = 2
2 , 2swapped 
j = 3
arr[3] = 3
3 , 3swapped 
j = 4
arr[4] = 5
5 , 5swapped 
j = 5
arr[5] = 12
12 , 12swapped 
j = 6
arr[6] = 6
6 , 6swapped 
j = 7
arr[7] = 7
7 , 7swapped 
j = 8
arr[8] = 10
10 , 10swapped 
j = 9
arr[9] = 8
8 , 8swapped 
j = 10
arr[10] = 9
9 , 9swapped 
j = 11
arr[11] = 11
11 , 11swapped 
j = 12
13 , 13swapped 
high = 11
PARTITION HAPPENED 
--PARTITION STARTED--
pi = 11
arr[0] = 1
1 , 1swapped 
j = 1
arr[1] = 4
4 , 4swapped 
j = 2
arr[2] = 2
2 , 2swapped 
j = 3
arr[3] = 3
3 , 3swapped 
j = 4
arr[4] = 5
5 , 5swapped 
j = 5
arr[5] = 12
arr[6] = 6
6 , 12swapped 
j = 6
arr[7] = 7
7 , 12swapped 
j = 7
arr[8] = 10
10 , 12swapped 
j = 8
arr[9] = 8
8 , 12swapped 
j = 9
arr[10] = 9
9 , 12swapped 
j = 10
11 , 12swapped 
high = 9
PARTITION HAPPENED 
--PARTITION STARTED--
pi = 9
arr[0] = 1
1 , 1swapped 
j = 1
arr[1] = 4
4 , 4swapped 
j = 2
arr[2] = 2
2 , 2swapped 
j = 3
arr[3] = 3
3 , 3swapped 
j = 4
arr[4] = 5
5 , 5swapped 
j = 5
arr[5] = 6
6 , 6swapped 
j = 6
arr[6] = 7
7 , 7swapped 
j = 7
arr[7] = 10
arr[8] = 8
8 , 10swapped 
j = 8
9 , 10swapped 
high = 7
INSERTION_SORT CALLED 
val = 4
j=i= 1
early arr[1] = 4
after arr[1] = 4
val = 2
j=i= 2
early arr[1] = 4
after arr[1] = 2
val = 3
j=i= 3
early arr[2] = 4
after arr[2] = 3
val = 5
j=i= 4
early arr[4] = 5
after arr[4] = 5
val = 6
j=i= 5
early arr[5] = 6
after arr[5] = 6
val = 7
j=i= 6
early arr[6] = 7
after arr[6] = 7
val = 8
j=i= 7
early arr[7] = 8
after arr[7] = 8
--INSERTION SORT END--
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 
*/
