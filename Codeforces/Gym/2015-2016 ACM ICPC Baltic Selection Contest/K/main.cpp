#include <bits/stdc++.h>
using namespace std;
#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

const long long int MAX_NUM = 1000000000000000000LL;

long long int f[21] = {0};
set<long long int> check;

void build_set()
{
    // Such good method
    check.insert(f[1]);
    for (set<long long int>::iterator it = check.begin(); it != check.end();
         it++) {
        for (int i = 1; i <= 20; i++) {
            if (MAX_NUM / f[i] >= *it) {
                check.insert(f[i] * (*it));
            }
        }
    }
}

/*
Greedy fails->72
*/

int main()
{
    f[0] = 1;
    for (long long int i = 1; i < 21; i++) {
        f[i] = f[i - 1] * i;
    }

    build_set();

    int n;
    while (scanf("%d", &n) == 1) {
        while (n--) {
            long long int temp;
            scanf("%lld", &temp);

            if (check.find(temp) != check.end())
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
