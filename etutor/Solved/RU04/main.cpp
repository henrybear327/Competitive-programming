#include <cstdio>

int a, b, c, A, B, C, D;
bool dfs(int x, int y, int z)
{
    if(x > a || y > b || z > c)
	return false;
    long long int sum = (long long int)x * A;
    sum += (long long int)y * B;
    sum += (long long int)z * C;
    if (sum == (long long int)D) {
        return true;
    } else if (sum > (long long int)D)
        return false;
    else {
        if (!dfs(x + 1, y, z))
            if (!dfs(x, y + 1, z))
                if (!dfs(x, y, z + 1))
                    return false;
        return true;
    }
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        scanf("%d %d %d %d %d %d %d", &D, &a, &b, &c, &A, &B, &C);

        printf("%s\n", dfs(0, 0, 0) ? "yes" : "no");
    }

    return 0;
}
