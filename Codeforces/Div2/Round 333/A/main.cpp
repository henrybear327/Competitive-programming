#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int n, b;
    scanf("%d %d", &n, &b);

    long long int first = 0;
    int inp[20];
    for(int i = 0; i< n; i++) {
        scanf("%d", &inp[i]);
    }

    long long int factor = 1;
    for(int i = 1; i < n; i++) {
        factor *= b;
    }

    for(int i = 0; i < n; i++) {
        first += inp[i] * factor;
        factor /= b;
    }
    // printf("%lld\n", first);


    scanf("%d %d", &n, &b);
    long long int second = 0;
    for(int i = 0; i< n; i++) {
        scanf("%d", &inp[i]);
    }

    factor = 1;
    for(int i = 1; i < n; i++) {
        factor *= b;
    }

    for(int i = 0; i < n; i++) {
        second += inp[i] * factor;
        factor /= b;
    }

    if(first == second)
        printf("=\n");
    else if(first > second)
        printf(">\n");
    else
        printf("<\n");

    return 0;
}
