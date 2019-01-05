#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);
    char inp[n + 10];
    scanf("%s", inp);

    int i = 0, inc = 1;
    while (i < n) {
        printf("%c", inp[i]);

        i += inc;
        inc++;
    }

    return 0;
}
