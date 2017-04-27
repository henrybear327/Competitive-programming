#include <bits/stdc++.h>

using namespace std;

void change(int &a, int &b)
{
    int tmp = b;
    b = a + b;
    a = a - tmp;
}

int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> inp;
    int g = 0; // default value can't be 1, come on bro
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);

        inp.push_back(tmp);
        g = gcd(g, tmp);
    }

    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if ((inp[i - 1] % 2 == 1) && (inp[i] % 2 == 1)) {
            change(inp[i - 1], inp[i]);
            cnt++;
        }
    }

    for (int i = 1; i < n; i++) {
        if ((inp[i - 1] % 2 == 1) || (inp[i] % 2 == 1)) {
            change(inp[i - 1], inp[i]);
            change(inp[i - 1], inp[i]);
            cnt += 2;
        }
    }

    printf("YES\n");
    printf("%d\n", g > 1 ? 0 : cnt);

    return 0;
}
