#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    char inp[111], cand[111];
    fgets(inp, 111, stdin);
    fgets(cand, 111, stdin);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < strlen(cand); j++) {
            if (inp[i] == cand[j]) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}
