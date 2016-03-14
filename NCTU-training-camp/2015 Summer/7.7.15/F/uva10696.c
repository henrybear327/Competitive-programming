#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int f91(int N)
{
    if (N <= 100)
        return f91(f91(N + 11));
    else
        return N - 10;
}

int main()
{
    int N;
    while (scanf("%d", &N) != EOF && N) {
        printf("f91(%d) = %d\n", N, f91(N));
    }

    return 0;
}