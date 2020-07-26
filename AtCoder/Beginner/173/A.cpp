#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i < 11; i++) {
        if (1000 * i - n >= 0) {
            printf("%d\n", 1000 * i - n);
            return 0;
        }
    }

    return 0;
}
