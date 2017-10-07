#include <bits/stdc++.h>

using namespace std;

struct Data {
    Data() {
        cnt = 1;
        width = 0;
    }

    int cnt;
    int width;
};

void solve(int ncase)
{
    int n;
    scanf("%d", &n);
    int seq[n], w[n];
    Data lis[n], lds[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &seq[i]);
    for(int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        lis[i].width = lds[i].width = w[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(seq[j] > seq[i]) {
                lis[j].cnt = max(lis[j].cnt, lis[i].cnt + 1);
                lis[j].width = max(lis[j].width, lis[i].width + w[j]);
            }

            if(seq[j] < seq[i]) {
                lds[j].cnt = max(lds[j].cnt, lds[i].cnt + 1);
                lds[j].width = max(lds[j].width, lds[i].width + w[j]);
            }
        }
    }
    
    /*
    for(int i = 0; i < n; i++)
        printf("(%d, %d)%c", lis[i].cnt, lis[i].width, i == n - 1 ? '\n' : ' ');
    for(int i = 0; i < n; i++)
        printf("(%d, %d)%c", lds[i].cnt, lds[i].width, i == n - 1 ? '\n' : ' ');
    */

    int mn_ans = INT_MIN, mx_ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        mn_ans = max(mn_ans, lds[i].width);

        mx_ans = max(mx_ans, lis[i].width);
    }
    // printf("%d %d\n", mx_ans, mn_ans);

    if(mx_ans >= mn_ans)
        printf("Case %d. Increasing (%d). Decreasing (%d).\n", ncase, mx_ans, mn_ans);
    else
        printf("Case %d. Decreasing (%d). Increasing (%d).\n", ncase, mn_ans, mx_ans);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for(int i = 1; i <= ncase; i++)
        solve(i);

    return 0;
}
