# Minimum cuts required to convert a palindromic string to a different palindromic string




Given palindromic string <strong>s</strong>, the task is to find minimum <strong>k</strong>, such that you can cut this string into <strong>k+1</strong> parts, and then unite them in such a way that the final string will be a palindrome and it won't be equal to the initial string <strong>s</strong>. If it is impossible then print <strong>-1</strong>.

<strong>Examples:</strong>
<pre>
<strong>Input : string = "civic"</strong>
<strong>Output : 2</strong>
Explanation : ci | v | ic --&gt; ic | v | ci --&gt; icvci
<strong>Input : string = "gggg"</strong>
<strong>Output : -1</strong>
<strong>Input : string = "redder"</strong>
<strong>Output : 1</strong>
Explanation : red | der --&gt; der | red --&gt; derred
<strong>Input : string = "aaaasaaaa"</strong>
<strong>Output : -1</strong>
</pre>

<strong>Approach 1:</strong> It is given that formed palindromic string should be different from the given string.
So when our string consists of n or n-1 (when n is odd) equal characters, then there is no way to get the answer. For example -
<pre>
<strong>String : "aaaasaaaa"</strong>
<strong>String : "aaaa"</strong>
</pre>
Above strings can not form palindrome other than the given one.
Otherwise, cut the longest prefix of s of length <strong>l</strong>, that consists of equal characters of length equal to <strong>l-1</strong>. Now similarly cut suffix of length <strong>l-1</strong>, and call remaining part as mid.
Now we have <strong>prefix = s[1..l]</strong> and suff = <strong>s[(n-l+1)..n]</strong>. Swap prefix and suffix, then unite all three parts together and keep mid as it is.
<pre>
<strong>prefix + mid + suffix != suffix + mid + prefix</strong>
</pre>
So clearly we can get the answer in two cuts. Finally you just have to check if it is possible to get answer in one cut. For that just cut one element from end and append it at front and continue this cyclic shift. During this if we get a palindromic string other then the given one then it means we can get answer in just one cut.
Below is the implementation of above approach:

```cpp
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
```
<div class = 'outputDiv'>
<b>Output:</b>
<pre>
2
</pre>
</div>
<strong>Time Complexity : </strong>O(N<sup>2</sup>)
 
<strong>Efficient Approach:</strong> Again if our string consists of n or n-1 (when n is odd) equal characters, then there is no way to get the answer.
Now, divide this problem into two parts that whether the string length is <strong>even</strong> or <strong>odd</strong>.

If the string length is <strong>odd</strong> then we always have a middle element in it so just make 2 cuts around the middle element and split the string into three segments and swap first and third segments.
Say, we have a string:
<pre><strong>nolon</strong> --&gt; <strong>no | l | on</strong> --&gt; <strong>on | l | no</strong> --&gt; <strong>onlno</strong></pre>
If the string length is <strong>even</strong> then check whether the half string is itself a palindromic string or not.
If so then:
<ol>
<li>Split a string recursively into two parts and check whether the resulting half string is a palindrome or not.</li>
<li>If string became of odd length then simply return 2.
<pre><strong>asaasa</strong> --&gt; <strong>as | aa | sa</strong> --&gt; <strong>sa | aa | as</strong> --&gt; <strong>saaaas</strong></pre></li>
<li>If resulting string is not a palindrome then return 1.
<pre><strong>toottoot</strong> --&gt; <strong>to | ottoot</strong> --&gt; <strong>ottoot | to</strong> --&gt; <strong>ottootto</strong></pre></li>
</ol>
Else we can cut this string from the middle, form two segments and swap each other.
<strong>For Example</strong>:
<pre><strong>voov</strong> --&gt; <strong>vo | ov</strong> --&gt; <strong>ov | vo</strong> --&gt; <strong>ovvo</strong></pre>
Below is the implementation of above approach:
 
 
```cpp
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
```
<div class = 'outputDiv'>
<b>Output:</b>
<pre>
2
</pre>
</div>
<strong>Time Complexity : </strong>O(N)











