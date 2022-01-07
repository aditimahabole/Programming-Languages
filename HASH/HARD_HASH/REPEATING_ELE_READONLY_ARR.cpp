//https://www.geeksforgeeks.org/find-one-multiple-repeating-elements-read-array/
//read only array : array cannot be modified
#include <bits/stdc++.h>
using namespace std;
int findRepeatingNumber(const int arr[], int n)
{
    cout<<"----------------------------------"<<endl;
	int sq = sqrt(n);
	cout<<"sq = "<<sq<<endl;
	
	int range = (n / sq) + 1;
	cout<<"range = "<<range<<endl;
	cout<<"----------------------------------"<<endl;
	int count[range] = {0};
	cout<<"=================================="<<endl;
	for (int i = 0; i <= n; i++)
	{
	    cout<<"----------------------------------"<<endl;
	    cout<<"arr[i] - 1/sq = "<<(arr[i] - 1)/sq<<endl;
	    cout<<"arr[i] = "<<arr[i]<<endl;
		count[(arr[i] - 1) / sq]++;
		cout<<"count[(arr[i] - 1) / sq]++ = "<<count[(arr[i] - 1)/sq]<<endl;
		cout<<"----------------------------------"<<endl;
	}
	cout<<"=================================="<<endl;
	cout<<"----------------------------------"<<endl;
	int selected_block = range - 1;
	cout<<"selected_block = "<<selected_block<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<"=================================="<<endl;
	for (int i = 0; i<range - 1; i++)
	{
	    cout<<"----------------------------------"<<endl;
	    cout<<"count[i] = "<<count[i]<<endl;
	    cout<<"sq = "<<sq<<endl;
	    
		if (count[i] > sq)
		{
		    cout<<"*********************"<<endl;
			selected_block = i;
			cout<<"selected_block = "<<selected_block<<endl;
			cout<<"*********************"<<endl;
			break;
		}
		cout<<"----------------------------------"<<endl;
	}
	cout<<"=================================="<<endl;
	unordered_map<int, int> m;
	cout<<"=================================="<<endl;
	for (int i = 0; i <= n; i++)
	{
	cout<<"----------------------------------"<<endl;
	cout<<"selected_block = "<<selected_block<<endl;
	cout<<"sq = "<<sq<<endl;
	cout<<"selected_block * sq = "<<selected_block*sq<<endl;
	cout<<"(selected_block + 1) * sq = "<<(selected_block + 1)*sq<<endl;
	cout<<"arr[i] = "<<arr[i]<<endl;
		if ( ((selected_block * sq) < arr[i]) &&
				(arr[i] <= ((selected_block + 1) * sq)))
		{
			m[arr[i]]++;

			// repeating element found
			if (m[arr[i]] > 1)
				return arr[i];
		}
	cout<<"----------------------------------"<<endl;
	}
	cout<<"=================================="<<endl;
	return -1;
}
int main()
{

	const int arr[] = { 1, 1, 2, 3, 5, 4 };
	int n = 5;
    cout<<findRepeatingNumber(arr, n)<<endl;
	cout<<" is One of the numbers repeated in the array"<<endl;
}
/* OUTPUT :
/tmp/KbF2Yk4ZKg.o
----------------------------------
sq = 2
range = 3
----------------------------------
==================================
----------------------------------
arr[i] - 1/sq = 0
arr[i] = 1
count[(arr[i] - 1) / sq]++ = 1
----------------------------------
----------------------------------
arr[i] - 1/sq = 0
arr[i] = 1
count[(arr[i] - 1) / sq]++ = 2
----------------------------------
----------------------------------
arr[i] - 1/sq = 0
arr[i] = 2
count[(arr[i] - 1) / sq]++ = 3
----------------------------------
----------------------------------
arr[i] - 1/sq = 1
arr[i] = 3
count[(arr[i] - 1) / sq]++ = 1
----------------------------------
----------------------------------
arr[i] - 1/sq = 2
arr[i] = 5
count[(arr[i] - 1) / sq]++ = 1
----------------------------------
----------------------------------
arr[i] - 1/sq = 1
arr[i] = 4
count[(arr[i] - 1) / sq]++ = 2
----------------------------------
==================================
----------------------------------
selected_block = 2
----------------------------------
==================================
----------------------------------
count[i] = 3
sq = 2
*********************
selected_block = 0
*********************
==================================
==================================
----------------------------------
selected_block = 0
sq = 2
selected_block * sq = 0
(selected_block + 1) * sq = 2
arr[i] = 1
----------------------------------
----------------------------------
selected_block = 0
sq = 2
selected_block * sq = 0
(selected_block + 1) * sq = 2
arr[i] = 1
1
 is One of the numbers repeated in the array
*/
