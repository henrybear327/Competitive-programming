#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

const ll M = ((ll)1e9 + 7);

ll a, b, x, n;

void mul(ll p[2][2], ll q[2][2])
{
    ll tmp[2][2];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                tmp[i][j] = (tmp[i][j] + (p[i][k] * q[k][j]) % M) % M;
            }
        }
    }

    memcpy(p, tmp, sizeof(tmp));
}

ll fast_pow(ll exp)
{
    ll base[2][2] = {{a, b}, {0, 1}};

    // res = base ^ n
    ll res[2][2] = {{1, 0}, {0, 1}};
    while (exp) {
        if (exp & 1) {
            mul(res, base);
        }
        mul(base, base);
        exp >>= 1;

        /*
        printf("res\n");
        for(int i = 0; i < 2; i++)
                for(int j = 0; j < 2; j++)
                        printf("%lld%c", res[i][j], j == 1 ? '\n' : ' ');
        printf("base\n");
        for(int i = 0; i < 2; i++)
                for(int j = 0; j < 2; j++)
                        printf("%lld%c", base[i][j], j == 1 ? '\n' : ' ');
        */
    };

    // res1 = res * [x, 1]
    ll res1 = (res[0][0] * x % M + res[0][1]) % M;
    return res1 % M;
}

int main()
{
    scanf("%lld %lld %lld %lld", &a, &b, &n, &x);

    // fast pow
    printf("%lld\n", fast_pow(n));

    return 0;
}
