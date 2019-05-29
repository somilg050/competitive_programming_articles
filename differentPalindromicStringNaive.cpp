// CPP program to solve the above problem 
  
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to check if string is palindrome or not 
bool isPalindrome(string s) 
{ 
    for (int i = 0; i < s.length(); ++i) { 
        if (s[i] != s[s.length() - i - 1]) { 
            return false; 
        } 
    } 
    return true; 
} 
  
// Function to check if it is possible to 
// get result by making just one cut 
bool ans(string s) 
{ 
    string s2 = s; 
  
    for (int i = 0; i < s.length(); ++i) { 
        // Appending last element in front 
        s2 = s2.back() + s2; 
        // Removing last element 
        s2.pop_back(); 
  
        // Checking whether string s2 is palindrome 
        // and different from s. 
        if (s != s2 && isPalindrome(s2)) { 
            return true; 
        } 
    } 
    return false; 
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
    if (*max_element(cnt, cnt + 25) >= (s.length() - 1)) { 
        return -1; 
    } 
    else { 
        // Return 1 if it is possible to get palindromic 
        // string in just one cut. 
        // Else we can always reached in two cuttings. 
        return (ans(s) ? 1 : 2); 
    } 
} 
  
// Driver Code 
int main() 
{ 
  
    string s = "nolon"; 
  
    cout << solve(s); 
  
    return 0; 
} 
