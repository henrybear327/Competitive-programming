#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int main()
{
    map<ll, pair<int, int> > ma;
    int n = 10;

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8 , 9, 0};

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            ma.insert(make_pair(a[i] + a[j], make_pair(i, j)));

    map<ll, pair<int, int> >::iterator it = ma.lower_bound(10);
    printf("%lld %d %d\n", it->first, it->second.first, it->second.second);

    return 0;
}
