#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int inp[100][100];
int n;
void check(int i, int j)
{
    if (inp[i][j] && inp[i][j + 1] && inp[i][j - 1] && inp[i + 1][j] &&
        inp[i - 1][j]) {
        inp[i][j] = inp[i][j + 1] = inp[i][j - 1] = inp[i + 1][j] = inp[i - 1][j] =
                                        0;
   } 
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char c[n + 10];
        scanf("%s", c);

        for (int j = 0; j < n; j++) {
            inp[i][j] = c[j] == '#' ? 1 : 0;
        }
    }

    bool error = false;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (inp[i][j] == 1)
                check(i, j);
        }
    }

    for(int i = 0; i < n; i++) 
	for(int j = 0; j < n; j++)
	    if(inp[i][j])
		error = true;

    printf("%s\n", error ? "NO" : "YES");

    return 0;
}
