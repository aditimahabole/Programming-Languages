// CPP program to implement direct index mapping
// with negative values allowed.
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// Since array is global, it is initialized as 0.
bool has[MAX + 1][2];

// searching if X is Present in the given array
// or not.
bool search(int X)
{
	if (X >= 0)
	{
		if (has[X][0] == 1)
		{
		    return true;
		}
			
		else
		{
		    return false;
		}
		
	}

	// if X is negative take the absolute
	// value of X.
	X = abs(X);//making X positive
	if (has[X][1] == 1)
	{
	    return true;
	}
		

	return false;
}

void insert(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		if (arr[i] >= 0)
		{
		   has[arr[i]][0] = 1; 
		   cout<<"has[arr[i]][0] : "<<has[arr[i]][0]<<" and arr[i] :  "<<arr[i]<<endl;
		}
		else
		{
		    has[abs(arr[i])][1] = 1;
		    cout<<"hash[arr[i]][1] : "<<has[arr[i]][0]<<" and arr[i] :  "<<arr[i]<<endl;
		}
	
			
	}
}

// Driver code
int main()
{
    int n;
    cout<<"ENTER SIZE : "<<endl;
    cin>>n;
    int arr[n];
	//int arr[] = { -1, 9, -5, -8, -5, -2 };
	//int n = sizeof(a)/sizeof(a[0]);
	cout<<"ENTER ELEMENTS : "<<endl;
	for(int i=0 ;i<n;i++)
	{
	    cin>>arr[i];
	}
	insert(arr, n);
	int X ;
	cout<<"ENTER ELEMENT YOU WANT TO SEARCH : "<<endl;
	cin>>X;
	if (search(X) == true)
	cout << "Present";
	else
	cout << "Not Present";
	return 0;
}
