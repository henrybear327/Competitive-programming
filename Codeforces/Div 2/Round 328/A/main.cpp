#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int inp[8][8];
    for (int i = 0; i < 8; i++) {
        char input[100];
        fgets(input, 100, stdin);
        for (int j = 0; j < 8; j++) {
            if (input[j] == '.')
                inp[i][j] = 0;
            else if (input[j] == 'W') {
                inp[i][j] = 1;
            } else {
                inp[i][j] = 2;
            }
        }
    }

    int b = 0, w = 8;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (inp[j][i] != 0) {
                if (inp[j][i] == 1) {
                    w = min(w, j);
                }
                break;
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 7; j >= 0; j--) {
            if (inp[j][i] != 0) {
                if (inp[j][i] == 2) {
                    b = max(b, j);
                }
                break;
            }
        }
    }
    printf("%c\n", w <= 7 - b ? 'A' : 'B');
    // printf("%c\n", w < 8 - b ? 'A' : 'B');

    return 0;
}
