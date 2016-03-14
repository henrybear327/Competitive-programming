#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <bitset>
#include <list>
#include <algorithm>
#include <climits>
using namespace std;

#define lson 2 * i
#define rson 2 * i + 1
#define LS l, mid, lson
#define RS mid + 1, r, rson
#define UP(i, x, y) for (i = x; i <= y; i++)
#define DOWN(i, x, y) for (i = x; i >= y; i--)
#define MEM(a, x) memset(a, x, sizeof(a))
#define W(a) while (a)
#define gcd(a, b) __gcd(a, b)
#define LL long long
#define N 100005
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define lowbit(x) (x & -x)
const int mod = 1e9 + 7;

char s1[N], s2[N], s3[N];
int len1, len2, len3;
int h1[30], h2[30], h3[30];
int cnt2, cnt3, cnt;

int main()
{
    int i, j, k;
    while (~scanf("%s%s%s", s1, s2, s3)) {
        len1 = strlen(s1);
        len2 = strlen(s2);
        len3 = strlen(s3);
        MEM(h1, 0);
        MEM(h2, 0);
        MEM(h3, 0);
        for (i = 0; i < len1; i++)
            h1[s1[i] - 'a']++;
        for (i = 0; i < len2; i++)
            h2[s2[i] - 'a']++;
        for (i = 0; i < len3; i++)
            h3[s3[i] - 'a']++;
        cnt = 0;

        for (i = 1;; i++) {
            int p = N;
            for (j = 0; j < 26; j++) {
                if (h1[j] - h2[j] * i < 0) {
                    p = 0;
                    break;
                }
            }
            if (!p)
                break;
            int p2 = N;
            for (j = 0; j < 26; j++) {
                if (h3[j]) {
                    p2 = min(p2, (h1[j] - h2[j] * i) / h3[j]);
                }
            }
            if (i + p2 > cnt) {
                cnt = i + p2;
                cnt2 = i;
                cnt3 = p2;
            }
        }
        for (i = 1;; i++) {
            int p = N;
            for (j = 0; j < 26; j++) {
                if (h1[j] - h3[j] * i < 0) {
                    p = 0;
                    break;
                }
            }
            if (!p)
                break;
            int p2 = N;
            for (j = 0; j < 26; j++) {
                if (h2[j]) {
                    p2 = min(p2, (h1[j] - h3[j] * i) / h2[j]);
                }
            }
            if (i + p2 > cnt) {
                cnt = i + p2;
                cnt3 = i;
                cnt2 = p2;
            }
        }
        for (i = 0; i < cnt2; i++)
            printf("%s", s2);
        for (i = 0; i < cnt3; i++)
            printf("%s", s3);
        for (i = 0; i < 26; i++) {
            for (j = 0; j < h1[i] - cnt2 * h2[i] - cnt3 * h3[i]; j++)
                printf("%c", i + 'a');
        }
        printf("\n");
    }

    return 0;
}