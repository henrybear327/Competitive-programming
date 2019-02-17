#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i < 32; i++) {
        if ((1 << i) > n) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
