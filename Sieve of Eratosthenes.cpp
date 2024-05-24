// https://prepinsta.com/samsung-coding-questions-and-answers/ 
// For finding prime numbers till n
// asked in Samsung R&D

// Problem Approach
// The problem requires sorting students based on specific rules related to the ASCII values of their initials:

// Prime values go first: Students whose initials have a prime ASCII value should go out before those with a composite ASCII value.
// Sorting among primes: Among students with prime ASCII values, those with a smaller ASCII value should go out first.
// Sorting among composites: Among students with composite ASCII values, those with a larger ASCII value should go out first.


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Sieve of Eratosthenes
// For finding primes 
// this needs pre computation 
void find_primes(vector<int>&prime){
    for(int i=2;i*i<128;i++){
        if(prime[i] == 1){
            for(int j = i*i;j<128;j+=i){
                prime[j] = 0;
            }
        }
    }
    return;
}

int main() {
    string input = "Kkunjkhahorin";
    
    
    // range given is from 33 to 128
    // but we will use from 2 to 128
    vector<int>prime(128,1);
    prime[0] = 0;
    prime[1] = 0;
    
    // doing precomputation of primes till 128
    find_primes(prime);
    
    string prime_chars = "";
    string const_chars = "";
    for(auto c : input){
        if(prime[c] == 1)prime_chars+=c;
        else const_chars+=c;
    }
    
    sort(prime_chars.begin(),prime_chars.end());
    sort(const_chars.rbegin(),const_chars.rend());
    string result = prime_chars+const_chars;
    cout<<"ANS : "<<result<<endl;
    return 0;
}
