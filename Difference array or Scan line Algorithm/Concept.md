[Important blog](https://codeforces.com/blog/entry/78762)

# An Introduction To Difference Arrays or Scan Line Algorithm

## The Problem

Given \( Q \) ranges of the form \([L_i, R_i]\), find for each point \( x \in [1, N] \) the number of ranges that contain that point.

- \( 1 \leq N, Q \leq 10^7 \)
- \( 1 \leq L_i \leq R_i \leq 10^7 \)

## The Solution

One solution is to loop over each element for each range, but this takes \( O(NQ) \) time. We can do better.

A difference array can be used to perform multiple range updates where we need to find the answer only after performing all the queries. We can do this in \( O(N) \) time and space. We can update an arbitrary range in \( O(1) \). It is only when we need to print our final answer that we perform an \( O(N) \) computation.

### Example

Let \( N = 5 \). Let's create an array `diff` of size \( N+2 \) which is initially filled with zeroes.

diff = [0, 0, 0, 0, 0, 0, 0]


Let \( Q = 4 \). Let's calculate the answer given these ranges: \([1, 3]\), \([4, 5]\), \([3, 4]\), \([1, 5]\).

Now, instead of iterating over each element of our array and adding the values, we can simply add the update value to index \( L \) of our difference array and subtract it from the index \( R+1 \) of our difference array. We need a difference array of size \( N+2 \) because we subtract the update value from \( R+1 \). It is possible for \( R \) to be equal to \( N \).

Our `diff` array after each query:

diff = [0, 0, 0, 0, 0, 0, 0]
diff = [0, 1, 0, 0, -1, 0, 0]
diff = [0, 1, 0, 0, 0, 0, -1]
diff = [0, 1, 0, 1, 0, -1, -1]
diff = [0, 2, 0, 1, 0, -1, -2]


Finally, we will run a loop from 2 to \( N \) (size of the array) and add `diff[i-1]` to `diff[i]`.

When we added our update value to index \( L \) and subtracted it from index \( R+1 \) and calculated prefix sums, for every range that we were supposed to increment by one, our update value got added to it. We subtracted the update value from index \( R+1 \) of the difference array so that when we are summing it up, the update value we added to index \( L \) does not get added to elements outside the update range.

We can also perform range increment queries this way. It is not necessary for us to add a fixed value of 1 to a range. It can be any arbitrary value.

### Code Example

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 5; // Size of array
    vector<int> elements{0, 1, 1, 1, 1, 1}; // 1 based indexing
    // n+2 because we are not using the 0-th index and we need one more element in the array.
    vector<int> diff(n + 2, 0); 
    
    int updateValue = 10;
    int l = 2, r = 5;
    diff[l] += updateValue;
    diff[r + 1] -= updateValue;
    
    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
        elements[i] += diff[i];
    }
    for (int i = 1; i <= n; i++) cout << elements[i] << " ";
    return 0;
}


```
The same logic applies for XOR between given ranges. By using a difference array, we can efficiently perform range updates and then calculate the final array after all updates in O(N) time.
```
