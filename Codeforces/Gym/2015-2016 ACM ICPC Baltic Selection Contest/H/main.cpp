#include <cstdio>
#include <algorithm>

using namespace std;


int main()
{
    long long int n, m;
    scanf("%I64d %I64d", &n, &m);
    if(m < n) //@@ come on man
        swap(n, m);
    printf("%I64d\n", n * (m - 1 + 2));

    return 0;
}
