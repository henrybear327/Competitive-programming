#include <cstdio>
#include <queue>
#include <algorithm>
#include <climits>

/*
1.If you change everything to long long int, you get TLE!!

2. Use inline function can SAVE 0.5 seconds!!!

clang-format-3.7 -i -style=LLVM main.cpp
&& astyle --style=linux main.cpp
&& g++ -Wall -Wextra -o main.o main.cpp
*/

using namespace std;

inline long long int check(int n1, int w1, int n2, int w2, int n3, int w3)
{
    return (long long int)n1 * w1 + (long long int)n2 * w2 +
           (long long int)n3 * w3;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int n;
        scanf("%d", &n);

        int inp[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &inp[i]);

        sort(inp, inp + n);

        for (int i = 1; i < n; i++)
            inp[i] += inp[i - 1];

        int left = n / 3, right = 2 * (n / 3);
        long long int ans = LLONG_MAX;

        while (right < n) {
            while (left < right) {
                if (left >= (right - left) && (right - left) >= (n - right)) {
                    ans = min(ans, check(left, inp[left - 1], right - left,
                                         inp[right - 1] - inp[left - 1], n - right,
                                         inp[n - 1] - inp[right - 1]));
                }

                // printf("%d\n", ans);
                left++;
            }
            right++;
            left = n / 3;
        }

        printf("%lld\n", ans);
    }

    return 0;
}
