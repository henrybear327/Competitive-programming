#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

constexpr int maxn = 2000010;
char s[maxn];

set<int> S;
int nextt[maxn][30];
int now[30];
int now_tot[maxn];

#define SIZE 4

void doit()
{
    scanf("%s", s);
    int len = strlen(s);
    int tot = 0;
    for (int i = len; i >= 1; i--) {
        S.insert(s[i - 1] - 'a');
        now_tot[i] = tot;
        if (S.size() == SIZE) {
            tot++;
            S.clear();
        }
    }
    if (tot == 0) {
        for (int i = 0; i < SIZE; i++)
            if (S.count(i) == 0) {
                printf("%c", i + 'a');
                return;
            }
    }
    memset(now, 0, sizeof(now));
    for (int i = len; i >= 1; i--) {
        for (int j = 0; j < SIZE; j++)
            nextt[i][j] = now[j];
        now[s[i - 1] - 'a'] = i;
    }
    int tmp = 0;
    for (int i = 0; i < SIZE; i++)
        if (S.count(i) == 0) {
            tmp = now[i];
            break;
        }
    printf("%c", s[tmp - 1]);
    for (int i = 1; i < tot; i++) {
        for (int j = 0; j < SIZE; j++)
            if (now_tot[nextt[tmp][j]] == now_tot[tmp] - 1) {
                tmp = nextt[tmp][j];
                printf("%c", s[tmp - 1]);
                break;
            }
    }
    for (int i = 0; i < SIZE; i++)
        if (nextt[tmp][i] == 0) {
            printf("%c", i + 'a');
            break;
        }
}

int main()
{
    doit();
    return 0;
}
