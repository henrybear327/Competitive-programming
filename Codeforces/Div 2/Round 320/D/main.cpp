#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int n,k, x;
    scanf("%d %d %d", &n, &k,&x);

    int mul = 1;
    for(int i = 0; i < k; i++)
        mul *= x;

    long long int inp[n + 1];
    for(int i = 1; i <= n; i++)
        scanf("%I64d", &inp[i]);

    long long int prefix[n + 1];
    memset(prefix, 0, sizeof(prefix));
    prefix[1] = inp[1];
    for(int i = 2; i <= n; i++)
        prefix[i] = prefix[i - 1] | inp[i];

    long long int suffix[n + 1];
    memset(suffix, 0, sizeof(suffix));
    suffix[n - 1] = inp[n];
    for(int i = n - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] | inp[i + 1];

    long long int ans = 0;
    for(int i = 1;i <= n; i++) {
        ans = max(ans, prefix[i - 1] | (inp[i] * mul) | suffix[i]);
    }

    printf("%I64d\n", ans);

    return 0;
}
