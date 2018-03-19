#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check(int num)
{
    while (num) {
        if ((num % 10) % 2 == 1)
            return false;
        num /= 10;
    }
    return true;
}

int solve()
{
    int num;
    scanf("%d", &num);

    int inc = 0, dec = 0;
    {
        int tmp = num;
        for (int i = 0;; i++) {
            if (check(tmp + i) == false)
                continue;
            else {
                inc = (tmp + i) - num;
                break;
            }
        }
    }

    {
        int tmp = num;
        for (int i = 0;; i--) {
            if (check(tmp + i) == false)
                continue;
            else {
                dec = num - (tmp + i);
                break;
            }
        }
    }

    return min(inc, dec);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %d\n", i, solve());
    }
}
