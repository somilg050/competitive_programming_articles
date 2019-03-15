# Count trailing zeros in b-ary (in the base/radix of b) representation of n!

### Given two integers n and b, write a function that returns the count of trailing zeroes in b-ary representation of n!

**Examples:**

<pre>
<strong>Input : n = 5 and b = 2</strong> 
<strong>Output : 3</strong>
5! = 120(10) = 1111000(2) having 3 trailing zeroes

<strong>Input : n = 6 and b = 9</strong>
<strong>Output : 1</strong>
6! = 720(10) = 880(9) having 1 trailing zeroes
</pre>

A simple method is to first calculate factorial of n and then convert that number in base b radix and count number of trailing zeroes in the result.
But this method cause overflow for even n = 100 as 
(100! = 933262154439441526816992......) which is pretty large so it's impossible doing given problem using this method.

**Approach:**
[Tex]
$$S(n) = \sum_{k\geq1} \left\lfloor  \frac{n}{p^k} \right\rfloor$$ 
[/Tex]
S(n) calculate number of factors of p in n!

Now Divide S by m to get a quotient Q and a remainder R: S = mQ + R. Then

$$Q = \left\lfloor \frac{S(n)}{m} \right\rfloor$$
$$Z(n) = min \left\{ \left\lfloor \frac{S(n)}{m} \right\rfloor \right\}$$

Following is the program based on the above formula

```c++
// Program to find trailing zeroes
// in b-ary representation of n!

#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Map to store the frequency of all prime numbers of n
map<ll,ll> m;

// A function to find all prime factors of a given number n
void primeFactors(long long n) {
    // Count Number of 2s that divide n
    while (n%2 == 0) { 
        m[2]++; 
        n = n/2; 
    }
    // Now start a loop from j = 3 to square root of n
    // as n is odd here. So we can increment j by 2
    for (int j = 3; j <= sqrt(n); j+=2) {
        // While j divides n, increase m[j] and divides n
        while (n%j == 0){ 
            m[j]++;
            n = n/j; 
        }
    }
    // When n is prime factor greater than 2
    if (n > 2)m[n]++;
}

// Function to find the number of factors of p in n!
long long solve(long long n, long long p){
    long long sum=0;

    while(n>0){
        sum+=n/p;
        n/=p;
    }
    return sum;
}

// Driver Function
int main(){

    long long n = 5;
    long long b = 2;

    // Declaring ans as max as possible
    // so that we can compare it with calculated
    // value to store minimum answer
    long long ans=4e18;

    // Find all prime factors of b
    primeFactors(b);

    // Iterator to iterate through map
    auto it=m.begin();

    while(it!=m.end()){
        // Initialize x with prime factor from map
        long long x=it->first;
        long long sum=solve(n,x);
        // Refer above for this.
        sum /= it->second;
        ans=min(ans,sum);
        it++;
    }
    // Print result
    cout<<ans<<endl;  
}
```

<pre>
<strong> OUTPUT : 3</strong>
</pre>
