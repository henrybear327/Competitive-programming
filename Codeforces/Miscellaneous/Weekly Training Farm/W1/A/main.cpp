#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int sum = 0;
    for(int i = 1; ; i++) {
        int digit = 0, cur = i;
        while(cur) {
            digit++;
            cur /= 10;
        }

        if(sum + digit < n) {
            sum += digit;
            continue;
        }

        // printf("%d %d %d\n", i, digit, sum);
        // getchar();

        // 1  2  3  4  5  6  7  8  9 10 11 12 13 <- n
        // 1  2  3  4  5  6  7  8  9  1  0  1  1

        int diff = n - sum;
        // printf("diff %d\n", diff);
        cur = i;
        int cnt = digit;
        while(cur) {
            if(cnt == diff) {
                printf("%d\n", cur % 10);
                return 0;
            }
            cnt--;
            cur /= 10;
        }
    }

    return 0;
}