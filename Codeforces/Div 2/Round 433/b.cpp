#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int cal(int n, int k)
{
    if(k <= n / 3)
        return k * 2;
    else {
        k -= n / 3;
        int rem = n % 3;
        if(rem > 0) { // 8 3, 7 2 cases
            if(rem == k) {
                return n / 3 * 2;
            } else if(rem == 2 && k == 1) {
                return n / 3 * 2 + 1;
            } else {
                k -= rem;
            }
        }

        return (n / 3) * 2 - k;
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    if (n == 1) {
        printf("0 0\n");
    } else if (k == 0) {
        printf("0 0\n");
    } else {
        int mx = cal(n, k);


        int mn = min(1, mx);
        printf("%d %d\n", mn, mx);
    }

    return 0;
}
