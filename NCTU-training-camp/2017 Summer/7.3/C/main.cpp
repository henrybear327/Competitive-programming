// http://codeforces.com/problemset/problem/26/A
#include <bits/stdc++.h>

using namespace std;

bool prime[3333];
bool isAlmostPrimeNumber(int n)
{
    int cnt = 0;
    for (int i = 0; i <= n; i++)
        if (prime[i] && n % i == 0)
            cnt++;

    return cnt == 2;
}

void build()
{
    fill(prime, prime + 3333, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i <= 3000; i++) {
        if (prime[i]) {
            // cout << i << endl;
            for (int j = i * i; j < 3333; j += i)
                prime[j] = false;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    build();

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (isAlmostPrimeNumber(i))
            ans++;
    }
    printf("%d\n", ans);

    return 0;
}