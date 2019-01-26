#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1;; i++) {
        if (n <= i * i) {
            printf("%d\n", i + i);
            break;
        } else if (n <= i * (i + 1)) {
            printf("%d\n", i + i + 1);
            break;
        }
    }

    return 0;
}
