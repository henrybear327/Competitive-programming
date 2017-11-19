#include <bits/stdc++.h>

using namespace std;

// considering only the consecutive elements is not enough
// 4
// 6 21 462 22

int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

int mn;
void solve(int inp[], int n)
{
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        int g = inp[i];
        for(int j = i + 1; g != 1 && j < n; j++) {
            cnt++;
            g = gcd(g, inp[j]); 
        }

        for(int j = 0; j < n; j++) {
            if(i == j)
                continue;
            if(inp[j] != 1)
                cnt++;
        }

        if(g == 1)
            mn = min(mn, cnt);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
    }

    mn = INT_MAX;
    solve(inp, n);
    // reverse(inp, inp + n);
    // solve(inp, n);

    printf("%d\n", mn == INT_MAX ? -1 : mn);

    return 0;
}
