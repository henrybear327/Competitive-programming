// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...

#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...

#endif

static int __initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

// BFS
// https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)
/*
What a solution!

Consider a graph which consists of number 0, 1,...,n as
its nodes. Node j is connected to node i via an edge if
and only if either j = i + (a perfect square number) or
i = j + (a perfect square number). Starting from node 0,
do the breadth-first search. If we reach node n at step
m, then the least number of perfect square numbers which
sum to n is m. Here since we have already obtained the
perfect square numbers, we have actually finished the
search at step 1.
*/

class Solution
{
public:
    int numSquares(int n)
    {
        const int N = n + 1;

        vector<int> square;
        for (int i = 1; i * i < N; i++)
            square.push_back(i * i);

        int *dp = new int[N];
        fill(dp, dp + N, INT_MAX);
        dp[0] = 0;
        for (auto i : square) {
            dp[i] = 1;
            for (int j = 0; i + j < N; j++) {
                dp[i + j] = min(dp[j] + 1, dp[i + j]);
            }
        }

        return dp[n];
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif