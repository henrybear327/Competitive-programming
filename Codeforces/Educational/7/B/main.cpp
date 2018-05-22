#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int main()
{
    int hh, mm;
    scanf("%d:%d", &hh, &mm);

    int n;
    scanf("%d", &n);

    mm += n;
    hh += mm / 60;
    mm %= 60;

    hh %= 24;

    printf("%02d:%02d\n", hh, mm);

    return 0;
}
