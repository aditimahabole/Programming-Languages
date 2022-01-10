//https://www.geeksforgeeks.org/print-words-together-set-characters/

// C++ program to print all words that have
// the same unique character set
//https://www.geeksforgeeks.org/print-words-together-set-characters/

// C++ program to print all words that have
// the same unique character set
#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26

// Generates a key from given string. The key
// contains all unique characters of given string in
// sorted order consisting of only distinct elements.
string getKey(string &str)
{
	bool visited[MAX_CHAR] = { false };

	// store all unique characters of current
	// word in key
	for (int j = 0; j < str.length(); j++)
	{
	    visited[str[j] - 'a'] = true ;
	    cout<<"___________________________________________"<<endl;
	    cout<<"str[j]                =  "<<str[j]<<endl;
	    cout<<"str[j]-'a'            =  "<<str[j]-'a'<<endl;
	    cout<<"visited[str[j] - 'a'] =  "<<visited[str[j] - 'a']<<endl;
	    cout<<"___________________________________________"<<endl;
	    
	}
	
	string key = "";
	//MAX_CHAR = 225 that is jaha tak chharacter hote molsty to 26 tak hi chal jata fir alphabets
	for (int j=0; j < MAX_CHAR; j++)
	{
	    if (visited[j])//if that j thai is for d j=3 to 
	    //visited[3] present hai kya jo ki hoga 
	    //so key =" "+ char me convert('a'+3);
	    // thet is key=d;
	   // and this goes on
	    {
	        cout<<"___________________________________________"<<endl;
	        key = key + (char)('a'+j);
	        cout<<"j     = "<<j<<endl;
	        cout<<"'a'+j = "<<(char)('a'+j)<<endl;
	        cout<<"key   = "<<key<<endl;
	        cout<<"___________________________________________"<<endl;
	    }
			
	}
		
	return key;
}

// Print all words together with same character sets.
void wordsWithSameCharSet(string words[], int n)
{
	// Stores indexes of all words that have same
	// set of unique characters.
	unordered_map <string, vector <int> > Hash;

	// Traverse all words
	for (int i=0; i<n; i++)
	{
	    cout<<"---------------"<<endl;
	    cout<<"the word is : "<<words[i]<<endl;
	    cout<<"---------------"<<endl;
	    //agar word dog hai to
	    //key dgo hoga that is sorted order me
		string key = getKey(words[i]);
		cout<<"********************"<<endl;
		cout<<"key obtained = "<<key<<endl;
		cout<<"********************"<<endl;
		Hash[key].push_back(i);//ans jin jin ka key same aaega 
		//uske index ko inserte kardenge vecotr me at index= that key
		//that is for dog key=dgo and for god also key=dgo
		//sp index jaha god hai and jaha dog hai i.e. 2 and 1 inset hoga vector me
		
	}

	// print all words that have the same unique character set
	for (auto it = Hash.begin(); it!=Hash.end(); it++)
	{
	for (auto v=(*it).second.begin(); v!=(*it).second.end(); v++)
		cout << words[*v] << ", ";
		//words[index daal rhe vector me se]
	cout << endl;
	}
}

// Driver program to test above function
int main()
{
// 	string words[] = 
// 	{ "dog","god",
// 	  "cat", "act", "tab",
// 	  "bats", "flow","wolfs",
// 	  "looped","poodle"
// 	 };
	 	string words[] = 
	{ "dog","god",
	  "cat", "act"
	 };
	int n = sizeof(words)/sizeof(words[0]);
	wordsWithSameCharSet(words, n);
	return 0;
}

/* OUTPUT : 
/tmp/HyEkKT48Ns.o
---------------
the word is : dog
---------------
___________________________________________
str[j]                =  d
str[j]-'a'            =  3
visited[str[j] - 'a'] =  1
___________________________________________
___________________________________________
str[j]                =  o
str[j]-'a'            =  14
visited[str[j] - 'a'] =  1
___________________________________________
___________________________________________
str[j]                =  g
str[j]-'a'            =  6
visited[str[j] - 'a'] =  1
___________________________________________
___________________________________________
j     = 3
'a'+j = d
key   = d
___________________________________________
___________________________________________
j     = 6
'a'+j = g
key   = dg
___________________________________________
___________________________________________
j     = 14
'a'+j = o
key   = dgo
___________________________________________
********************
key obtained = dgo
********************
---------------
the word is : god
---------------
___________________________________________
str[j]                =  g
str[j]-'a'            =  6
visited[str[j] - 'a'] =  1
___________________________________________
___________________________________________
str[j]                =  o
str[j]-'a'            =  14
visited[str[j] - 'a'] =  1
___________________________________________
___________________________________________
str[j]                =  d
str[j]-'a'            =  3
visited[str[j] - 'a'] =  1
___________________________________________
___________________________________________
j     = 3
'a'+j = d
key   = d
___________________________________________
___________________________________________
j     = 6
'a'+j = g
key   = dg
___________________________________________
___________________________________________
j     = 14
'a'+j = o
key   = dgo
___________________________________________
********************
key obtained = dgo
********************
---------------
the word is : cat---------------
___________________________________________
str[j]                =  c
str[j]-'a'            =  2
visited[str[j] - 'a'] =  1
___________________________________________
___________________________________________
str[j]                =  a
str[j]-'a'            =  0
visited[str[j] - 'a'] =  1
___________________________________________
___________________________________________
str[j]                =  t
str[j]-'a'            =  19
visited[str[j] - 'a'] =  1
___________________________________________
___________________________________________
j     = 0
'a'+j = a
key   = a
___________________________________________
___________________________________________
j     = 2
'a'+j = c
key   = ac
___________________________________________
___________________________________________
j     = 19
'a'+j = t
key   = act
___________________________________________
********************
key obtained = act
********************
---------------
the word is : act
---------------
___________________________________________
str[j]                =  a
str[j]-'a'            =  0
visited[str[j] - 'a'] =  1
___________________________________________
___________________________________________
str[j]                =  c
str[j]-'a'            =  2
visited[str[j] - 'a'] =  1
___________________________________________
___________________________________________
str[j]                =  t
str[j]-'a'            =  19
visited[str[j] - 'a'] =  1
___________________________________________
___________________________________________
j     = 0
'a'+j = a
key   = a
___________________________________________
___________________________________________
j     = 2
'a'+j = c
key   = ac
___________________________________________
___________________________________________
j     = 19
'a'+j = tkey   = act
___________________________________________
********************
key obtained = act
********************
cat, act, 
dog, god, 


*/
