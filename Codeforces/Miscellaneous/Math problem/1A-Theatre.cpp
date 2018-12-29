#include <cstdio>

int main()
{
    int n, m, a;

    scanf("%d %d %d", &n, &m, &a);
    n = n % a == 0 ? n / a : n / a + 1;
    m = m % a == 0 ? m / a : m / a + 1;

    printf("%I64d\n", (long long int) n * m);

    return 0;
}
