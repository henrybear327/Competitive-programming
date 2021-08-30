#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    const int cand[] = {7, 77, 777, 7777, 77777, 777777, 7777777};
    int n;
    scanf("%d", &n);

    for (int i = 0; i < 7; i++) {
        for (int j = 1; j * n <= cand[i]; j++) {
            if (j * n % cand[i] == 0) {
                printf("%d\n", j * n);
                return 0;
            }
        }
    }

    return 0;
}
