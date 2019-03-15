<h1 id="count-trailing-zeros-in-b-ary-in-the-baseradix-of-b-representation-of-n">Count trailing zeros in b-ary (in the base/radix of b) representation of n!</h1>
<h3 id="given-two-integers-n-and-b-write-a-function-that-returns-the-count-of-trailing-zeroes-in-b-ary-representation-of-n">Given two integers n and b, write a function that returns the count of trailing zeroes in b-ary representation of n!</h3>
<p><strong>Examples:</strong></p>
<pre><strong>Input : n = 5 and b = 2</strong> 
<strong>Output : 3</strong>
5! = 120(10) = 1111000(2) having 3 trailing zeroes

<strong>Input : n = 6 and b = 9</strong>
<strong>Output : 1</strong>
6! = 720(10) = 880(9) having 1 trailing zeroes
</pre>
<p>A simple method is to first calculate factorial of n and then convert that number in base b radix and count number of trailing zeroes in the result.<br>
But this method cause overflow for even n = 100 as<br>
(100! = 9332621544394415268169…) which is pretty large so it’s impossible doing given problem using this method.</p>
<p>Better Approach:</p>
<p><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>S</mi><mo>(</mo><mi>n</mi><mo>)</mo><mo>=</mo><munder><mo>∑</mo><mrow><mi>k</mi><mo>≥</mo><mn>1</mn></mrow></munder><mrow><mo fence="true">⌊</mo><mfrac><mi>n</mi><msup><mi>p</mi><mi>k</mi></msup></mfrac><mo fence="true">⌋</mo></mrow></mrow><annotation encoding="application/x-tex">S(n) = \sum_{k\geq1} \left\lfloor  \frac{n}{p^k} \right\rfloor</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathit" style="margin-right: 0.05764em;">S</span><span class="mopen">(</span><span class="mord mathit">n</span><span class="mclose">)</span><span class="mspace" style="margin-right: 0.277778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.277778em;"></span></span><span class="base"><span class="strut" style="height: 2.84729em; vertical-align: -1.39729em;"></span><span class="mop op-limits"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 1.05001em;"><span class="" style="top: -1.84789em; margin-left: 0em;"><span class="pstrut" style="height: 3.05em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mtight"><span class="mord mathit mtight" style="margin-right: 0.03148em;">k</span><span class="mrel mtight">≥</span><span class="mord mtight">1</span></span></span></span><span class="" style="top: -3.05em;"><span class="pstrut" style="height: 3.05em;"></span><span class=""><span class="mop op-symbol large-op">∑</span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 1.39729em;"><span class=""></span></span></span></span></span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="minner"><span class="mopen delimcenter" style="top: 0em;"><span class="delimsizing size3">⌊</span></span><span class="mord"><span class="mopen nulldelimiter"></span><span class="mfrac"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 1.10756em;"><span class="" style="top: -2.314em;"><span class="pstrut" style="height: 3em;"></span><span class="mord"><span class="mord"><span class="mord mathit">p</span><span class="msupsub"><span class="vlist-t"><span class="vlist-r"><span class="vlist" style="height: 0.775108em;"><span class="" style="top: -2.989em; margin-right: 0.05em;"><span class="pstrut" style="height: 2.7em;"></span><span class="sizing reset-size6 size3 mtight"><span class="mord mathit mtight" style="margin-right: 0.03148em;">k</span></span></span></span></span></span></span></span></span></span><span class="" style="top: -3.23em;"><span class="pstrut" style="height: 3em;"></span><span class="frac-line" style="border-bottom-width: 0.04em;"></span></span><span class="" style="top: -3.677em;"><span class="pstrut" style="height: 3em;"></span><span class="mord"><span class="mord mathit">n</span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.88044em;"><span class=""></span></span></span></span></span><span class="mclose nulldelimiter"></span></span><span class="mclose delimcenter" style="top: 0em;"><span class="delimsizing size3">⌋</span></span></span></span></span></span></span></span></p>
<p>S(n) calculate number of factors of p in n!</p>
<p>Now Divide S by m to get a quotient Q and a remainder R: S = mQ + R. Then</p>
<p><span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>Q</mi><mo>=</mo><mrow><mo fence="true">⌊</mo><mfrac><mrow><mi>S</mi><mo>(</mo><mi>n</mi><mo>)</mo></mrow><mi>m</mi></mfrac><mo fence="true">⌋</mo></mrow></mrow><annotation encoding="application/x-tex">Q = \left\lfloor \frac{S(n)}{m} \right\rfloor</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 0.87777em; vertical-align: -0.19444em;"></span><span class="mord mathit">Q</span><span class="mspace" style="margin-right: 0.277778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.277778em;"></span></span><span class="base"><span class="strut" style="height: 2.40003em; vertical-align: -0.95003em;"></span><span class="minner"><span class="mopen delimcenter" style="top: 0em;"><span class="delimsizing size3">⌊</span></span><span class="mord"><span class="mopen nulldelimiter"></span><span class="mfrac"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 1.427em;"><span class="" style="top: -2.314em;"><span class="pstrut" style="height: 3em;"></span><span class="mord"><span class="mord mathit">m</span></span></span><span class="" style="top: -3.23em;"><span class="pstrut" style="height: 3em;"></span><span class="frac-line" style="border-bottom-width: 0.04em;"></span></span><span class="" style="top: -3.677em;"><span class="pstrut" style="height: 3em;"></span><span class="mord"><span class="mord mathit" style="margin-right: 0.05764em;">S</span><span class="mopen">(</span><span class="mord mathit">n</span><span class="mclose">)</span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.686em;"><span class=""></span></span></span></span></span><span class="mclose nulldelimiter"></span></span><span class="mclose delimcenter" style="top: 0em;"><span class="delimsizing size3">⌋</span></span></span></span></span></span></span></span><br>
<span class="katex--display"><span class="katex-display"><span class="katex"><span class="katex-mathml"><math><semantics><mrow><mi>Z</mi><mo>(</mo><mi>n</mi><mo>)</mo><mo>=</mo><mi>m</mi><mi>i</mi><mi>n</mi><mrow><mo fence="true">{</mo><mrow><mo fence="true">⌊</mo><mfrac><mrow><mi>S</mi><mo>(</mo><mi>n</mi><mo>)</mo></mrow><mi>m</mi></mfrac><mo fence="true">⌋</mo></mrow><mo fence="true">}</mo></mrow></mrow><annotation encoding="application/x-tex">Z(n) = min \left\{ \left\lfloor \frac{S(n)}{m} \right\rfloor \right\}</annotation></semantics></math></span><span class="katex-html" aria-hidden="true"><span class="base"><span class="strut" style="height: 1em; vertical-align: -0.25em;"></span><span class="mord mathit" style="margin-right: 0.07153em;">Z</span><span class="mopen">(</span><span class="mord mathit">n</span><span class="mclose">)</span><span class="mspace" style="margin-right: 0.277778em;"></span><span class="mrel">=</span><span class="mspace" style="margin-right: 0.277778em;"></span></span><span class="base"><span class="strut" style="height: 2.40003em; vertical-align: -0.95003em;"></span><span class="mord mathit">m</span><span class="mord mathit">i</span><span class="mord mathit">n</span><span class="mspace" style="margin-right: 0.166667em;"></span><span class="minner"><span class="mopen delimcenter" style="top: 0em;"><span class="delimsizing size3">{</span></span><span class="minner"><span class="mopen delimcenter" style="top: 0em;"><span class="delimsizing size3">⌊</span></span><span class="mord"><span class="mopen nulldelimiter"></span><span class="mfrac"><span class="vlist-t vlist-t2"><span class="vlist-r"><span class="vlist" style="height: 1.427em;"><span class="" style="top: -2.314em;"><span class="pstrut" style="height: 3em;"></span><span class="mord"><span class="mord mathit">m</span></span></span><span class="" style="top: -3.23em;"><span class="pstrut" style="height: 3em;"></span><span class="frac-line" style="border-bottom-width: 0.04em;"></span></span><span class="" style="top: -3.677em;"><span class="pstrut" style="height: 3em;"></span><span class="mord"><span class="mord mathit" style="margin-right: 0.05764em;">S</span><span class="mopen">(</span><span class="mord mathit">n</span><span class="mclose">)</span></span></span></span><span class="vlist-s">​</span></span><span class="vlist-r"><span class="vlist" style="height: 0.686em;"><span class=""></span></span></span></span></span><span class="mclose nulldelimiter"></span></span><span class="mclose delimcenter" style="top: 0em;"><span class="delimsizing size3">⌋</span></span></span><span class="mclose delimcenter" style="top: 0em;"><span class="delimsizing size3">}</span></span></span></span></span></span></span></span></p>
<p>Following is the program based on the above formula</p>
<pre class=" language-cpp"><code class="prism  language-cpp"><span class="token comment">// Program to find trailing zeroes</span>
<span class="token comment">// in b-ary representation of n!</span>

<span class="token macro property">#<span class="token directive keyword">include</span><span class="token string">&lt;bits/stdc++.h&gt;</span></span>
<span class="token keyword">using</span> <span class="token keyword">namespace</span> std<span class="token punctuation">;</span>

<span class="token macro property">#<span class="token directive keyword">define</span> ll long long</span>

<span class="token comment">// Map to store the frequency of all prime numbers of n</span>
map<span class="token operator">&lt;</span>ll<span class="token punctuation">,</span>ll<span class="token operator">&gt;</span> m<span class="token punctuation">;</span>

<span class="token comment">// A function to find all prime factors of a given number n</span>
<span class="token keyword">void</span> <span class="token function">primeFactors</span><span class="token punctuation">(</span><span class="token keyword">long</span> <span class="token keyword">long</span> n<span class="token punctuation">)</span> <span class="token punctuation">{</span>
    <span class="token comment">// Count Number of 2s that divide n</span>
    <span class="token keyword">while</span> <span class="token punctuation">(</span>n<span class="token operator">%</span><span class="token number">2</span> <span class="token operator">==</span> <span class="token number">0</span><span class="token punctuation">)</span> <span class="token punctuation">{</span> 
        m<span class="token punctuation">[</span><span class="token number">2</span><span class="token punctuation">]</span><span class="token operator">++</span><span class="token punctuation">;</span> 
        n <span class="token operator">=</span> n<span class="token operator">/</span><span class="token number">2</span><span class="token punctuation">;</span> 
    <span class="token punctuation">}</span>
    <span class="token comment">// Now start a loop from j = 3 to square root of n</span>
    <span class="token comment">// as n is odd here. So we can increment j by 2</span>
    <span class="token keyword">for</span> <span class="token punctuation">(</span><span class="token keyword">int</span> j <span class="token operator">=</span> <span class="token number">3</span><span class="token punctuation">;</span> j <span class="token operator">&lt;=</span> <span class="token function">sqrt</span><span class="token punctuation">(</span>n<span class="token punctuation">)</span><span class="token punctuation">;</span> j<span class="token operator">+</span><span class="token operator">=</span><span class="token number">2</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
        <span class="token comment">// While j divides n, increase m[j] and divides n</span>
        <span class="token keyword">while</span> <span class="token punctuation">(</span>n<span class="token operator">%</span>j <span class="token operator">==</span> <span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">{</span> 
            m<span class="token punctuation">[</span>j<span class="token punctuation">]</span><span class="token operator">++</span><span class="token punctuation">;</span>
            n <span class="token operator">=</span> n<span class="token operator">/</span>j<span class="token punctuation">;</span> 
        <span class="token punctuation">}</span>
    <span class="token punctuation">}</span>
    <span class="token comment">// When n is prime factor greater than 2</span>
    <span class="token keyword">if</span> <span class="token punctuation">(</span>n <span class="token operator">&gt;</span> <span class="token number">2</span><span class="token punctuation">)</span>m<span class="token punctuation">[</span>n<span class="token punctuation">]</span><span class="token operator">++</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>

<span class="token comment">// Function to find the number of factors of p in n!</span>
<span class="token keyword">long</span> <span class="token keyword">long</span> <span class="token function">solve</span><span class="token punctuation">(</span><span class="token keyword">long</span> <span class="token keyword">long</span> n<span class="token punctuation">,</span> <span class="token keyword">long</span> <span class="token keyword">long</span> p<span class="token punctuation">)</span><span class="token punctuation">{</span>
    <span class="token keyword">long</span> <span class="token keyword">long</span> sum<span class="token operator">=</span><span class="token number">0</span><span class="token punctuation">;</span>

    <span class="token keyword">while</span><span class="token punctuation">(</span>n<span class="token operator">&gt;</span><span class="token number">0</span><span class="token punctuation">)</span><span class="token punctuation">{</span>
        sum<span class="token operator">+</span><span class="token operator">=</span>n<span class="token operator">/</span>p<span class="token punctuation">;</span>
        n<span class="token operator">/</span><span class="token operator">=</span>p<span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
    <span class="token keyword">return</span> sum<span class="token punctuation">;</span>
<span class="token punctuation">}</span>

<span class="token comment">// Driver Function</span>
<span class="token keyword">int</span> <span class="token function">main</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">{</span>

    <span class="token keyword">long</span> <span class="token keyword">long</span> n <span class="token operator">=</span> <span class="token number">5</span><span class="token punctuation">;</span>
    <span class="token keyword">long</span> <span class="token keyword">long</span> b <span class="token operator">=</span> <span class="token number">2</span><span class="token punctuation">;</span>

    <span class="token comment">// Declaring ans as max as possible</span>
    <span class="token comment">// so that we can compare it with calculated</span>
    <span class="token comment">// value to store minimum answer</span>
    <span class="token keyword">long</span> <span class="token keyword">long</span> ans<span class="token operator">=</span><span class="token number">4e18</span><span class="token punctuation">;</span>

    <span class="token comment">// Find all prime factors of b</span>
    <span class="token function">primeFactors</span><span class="token punctuation">(</span>b<span class="token punctuation">)</span><span class="token punctuation">;</span>

    <span class="token comment">// Iterator to iterate through map</span>
    <span class="token keyword">auto</span> it<span class="token operator">=</span>m<span class="token punctuation">.</span><span class="token function">begin</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>

    <span class="token keyword">while</span><span class="token punctuation">(</span>it<span class="token operator">!=</span>m<span class="token punctuation">.</span><span class="token function">end</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">)</span><span class="token punctuation">{</span>
        <span class="token comment">// Initialize x with prime factor from map</span>
        <span class="token keyword">long</span> <span class="token keyword">long</span> x<span class="token operator">=</span>it<span class="token operator">-</span><span class="token operator">&gt;</span>first<span class="token punctuation">;</span>
        <span class="token keyword">long</span> <span class="token keyword">long</span> sum<span class="token operator">=</span><span class="token function">solve</span><span class="token punctuation">(</span>n<span class="token punctuation">,</span>x<span class="token punctuation">)</span><span class="token punctuation">;</span>
        <span class="token comment">// Refer above for this.</span>
        sum <span class="token operator">/</span><span class="token operator">=</span> it<span class="token operator">-</span><span class="token operator">&gt;</span>second<span class="token punctuation">;</span>
        ans<span class="token operator">=</span><span class="token function">min</span><span class="token punctuation">(</span>ans<span class="token punctuation">,</span>sum<span class="token punctuation">)</span><span class="token punctuation">;</span>
        it<span class="token operator">++</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
    <span class="token comment">// Print result</span>
    cout<span class="token operator">&lt;&lt;</span>ans<span class="token operator">&lt;&lt;</span>endl<span class="token punctuation">;</span>  
<span class="token punctuation">}</span>
</code></pre>
<pre><strong> OUTPUT : 3</strong>
</pre>

