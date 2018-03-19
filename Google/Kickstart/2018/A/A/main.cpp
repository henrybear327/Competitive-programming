#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll conv(int num[], int len)
{
    ll res = 0;
    for (int i = 0; i < len; i++) {
        if (num[i] > 9) {
            res *= 10;
            res += (num[i] / 10 + 1);
        }
        res *= 10;
        res += num[i] % 10;
    }
    return res;
}

ll solve()
{
    char inp[20];
    scanf("%s", inp);
    int len = strlen(inp);

    int num[len], num1[len];
    for (int i = 0; i < len; i++) {
        num[i] = inp[i] - '0';
        num1[i] = inp[i] - '0';
    }
    ll orig = conv(num, len);

    ll incV = 0, decV = 0;
    {
        // case 909 -> 1000
        bool first = true;
        for (int i = 0; i < len; i++) {
            if (first == false)
                num[i] = 0;

            if (num[i] % 2 == 1) {
                if (first) {
                    num[i] += 1;
                    first = false;
                }
            }
        }

        incV = conv(num, len);
    }

    {
        bool first = true;
        for (int i = 0; i < len; i++) {
            if (first == false)
                num1[i] = 8;

            if (num1[i] % 2 == 1) {
                num1[i] -= 1;
                first = false;
            }
        }
        decV = conv(num1, len);
    }

    // printf("%lld %lld %lld\n", incV, orig, decV);
    return min(incV - orig, orig - decV);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %lld\n", i, solve());
    }
}
