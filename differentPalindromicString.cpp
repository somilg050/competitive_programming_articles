// CPP program to solve the above problem 

#include <bits/stdc++.h> 
using namespace std; 

// Recursive function to find minimum number 
// of cuts if length of string is even 
int solveEven(string s) 
{ 
	// If length is odd then return 2 
	if (s.length() % 2 == 1) 
		return 2; 

	// To check if half of palindromic string 
	// is itself a palindrome 
	string ls = s.substr(0, s.length() / 2); 

	string rs = s.substr(s.length() / 2, s.length()); 

	// If not then return 1 
	if (ls != rs) 
		return 1; 

	// Else call function with half palindromic string 
	return solveEven(ls); 
} 

// Function to find minimum number of cuts 
// If length of string is odd 
int solveOdd(string s) 
{ 
	return 2; 
} 

int solve(string s) 
{ 
	// If length is <=3 then it is impossible 
	if (s.length() <= 3) { 
		return -1; 
	} 

	// Array to store frequency of characters 
	int cnt[25] = {}; 

	// Store count of characters in a array 
	for (int i = 0; i < s.length(); i++) { 
		cnt[s[i] - 'a']++; 
	} 

	// Condition for edge cases 
	if (*max_element(cnt, cnt + 25) >= s.length() - 1) { 
		return -1; 
	} 

	// If length is even 
	if (s.length() % 2 == 0) 
		return solveEven(s); 

	// If length is odd 
	if (s.length() % 2 == 1) 
		return solveOdd(s); 
} 

// Driver Code 
int main() 
{ 
	string s = "nolon"; 

	cout << solve(s); 

	return 0; 
} 
