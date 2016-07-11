#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;
int N, M;
char A[MAX_N][MAX_M + 10];

int main() {
    scanf("%d %d", &N, &M);
    for (int r = 0; r < N; r++) {
        scanf("%s", A[r]);
    }

    int cnt = 0;
    int max_ = 0;
    int dir = +1;
    int c = 0;

    for (int r = 0; r < N; r++) {
        for (int i = 0; i < M; i++) {
            printf("(%d, %d)\n", r, c);
            if (A[r][c] == '.') {
                cnt++;
                max_ = max(max_ , cnt);
            }
            if (A[r][c] == 'L') {
                cnt = 0;
            }
            c += dir;
        }
        dir = -dir;
    }

    printf("%d\n", max_);

    return 0;
}
