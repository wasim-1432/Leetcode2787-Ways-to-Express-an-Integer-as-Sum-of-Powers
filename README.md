# 🚀 Ways to Express an Integer as Sum of Powers
### 💻 LeetCode 2787 | C++ | Recursion + Memoization (2D DP)

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue.svg" />
  <img src="https://img.shields.io/badge/Algorithm-Recursion-success.svg" />
  <img src="https://img.shields.io/badge/DP-Memoization-orange.svg" />
  <img src="https://img.shields.io/badge/Complexity-O(n²)-red.svg" />
  <img src="https://img.shields.io/badge/Status-Accepted-brightgreen.svg" />
</p>

---

## 📌 Problem Statement

Given two positive integers **n** and **x**, return the number of ways to express **n** as the sum of the **x-th power** of **unique positive integers**.

Since the answer can be very large, return it **modulo 10⁹ + 7**.

### ✨ Example

**Input**
```text
n = 10
x = 2
```

**Output**
```text
1
```

**Explanation**

```text
10 = 3² + 1²
```

---

## 💡 Approach

This solution is based on **Recursion + Memoization (Top-Down DP)**.

For every number we have **two choices**:

✅ Take the current number

❌ Skip the current number

Since every integer must be **unique**, after taking a number we move to the **next index**.

### Recursive Relation

```cpp
Ways(i, sum) =
Take Current Number +
Skip Current Number
```

---

## 🌳 Recursion Tree

```text
                    Solve(0,n)

                 /              \
          Take Current       Skip Current
               |                  |
       Solve(i+1,n-p)      Solve(i+1,n)

```

where

```text
p = coins[i]^x
```

---

## 🧠 Memoization

To avoid recomputing the same states repeatedly, we store answers in a **2D DP table**.

```cpp
dp[index][remaining_sum]
```

If already computed:

```cpp
if(dp[i][n] != -1)
    return dp[i][n];
```

---

## ⚙️ Algorithm

1. Generate all integers from **1 to n**
2. At every index:
   - Take current number (only once)
   - Skip current number
3. Store computed results in DP.
4. Return answer modulo **1e9+7**.

---

## ⏱️ Time Complexity

| Operation | Complexity |
|-----------|------------|
| Recursion + Memoization | **O(n²)** |

---

## 💾 Space Complexity

| Resource | Complexity |
|----------|------------|
| DP Table | **O(n²)** |
| Recursion Stack | **O(n)** |

---

## ✅ Features

- ✔️ Top-Down Dynamic Programming
- ✔️ Memoization
- ✔️ Unique Integers
- ✔️ Accepted on LeetCode
- ✔️ Beginner Friendly

---

## 🛠️ Concepts Used

- 🔹 Recursion
- 🔹 Dynamic Programming
- 🔹 Memoization
- 🔹 Backtracking Idea
- 🔹 Decision Making (Take / Not Take)

---

## 🧩 Code

```cpp
class Solution {
public:
    const int MOD = 1e9 + 7;

    int Solve(int i, int n, int x,
              vector<int> &coins,
              vector<vector<int>> &dp)
    {
        if(n == 0)
            return 1;

        if(i == coins.size())
            return 0;

        if(dp[i][n] != -1)
            return dp[i][n];

        int take = 0;

        long long p = pow(coins[i], x);

        if(p <= n)
            take = Solve(i + 1, n - p, x, coins, dp);

        int notTake = Solve(i + 1, n, x, coins, dp);

        return dp[i][n] = (take + notTake) % MOD;
    }

    int numberOfWays(int n, int x) {

        vector<int> coins;

        for(int i = 1; i <= n; i++)
            coins.push_back(i);

        vector<vector<int>> dp(coins.size(),
                               vector<int>(n + 1, -1));

        return Solve(0, n, x, coins, dp);
    }
};
```

---

## 🏆 Result

✅ **Accepted on LeetCode**

- ✔️ Runtime: Accepted
- ✔️ Memoization
- ✔️ Clean Recursive Solution

---

## 📚 Learning Outcomes

After solving this problem, you'll understand:

- ✅ Take / Not Take DP Pattern
- ✅ Recursion + Memoization
- ✅ Unique Selection Problems
- ✅ 2D Dynamic Programming
- ✅ State Representation

---

## ⭐ If you found this repository helpful

Give it a ⭐ on GitHub and share it with others!

Happy Coding! 🚀💙
