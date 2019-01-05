#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);

        tmp = tmp % 2 == 1 ? tmp : tmp - 1;
        printf("%d ", tmp);
    }

    return 0;
}
