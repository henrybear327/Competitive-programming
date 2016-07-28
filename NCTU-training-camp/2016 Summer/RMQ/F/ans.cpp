#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
#define maxn 1000017
#define maxm 100017
using namespace std;

struct node {
    int l, r;
    int id;
} q[maxm];

char s[maxn];
int c[maxn];
int ans[maxm];
stack<int> st;
int len;

int Lowbit(int x) // 2^k
{
    return x & (-x);
}

void update(int i, int x) // i点增量为x
{
    while (i <= len) {
        c[i] += x;
        i += Lowbit(i);
    }
}

int sum(int x) //区间求和 [1,x]
{
    int ans = 0;
    while (x) {
        ans += c[x];
        x -= Lowbit(x);
    }
    return ans;
}

bool cmp(node a, node b)
{
    return a.r < b.r;
}

int main()
{
    int m;

    while (~scanf("%s", s)) {
        int pos = 1;
        memset(c, 0, sizeof(c));
        while (!st.empty()) {
            st.pop();
        }
        len = strlen(s);
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &q[i].l, &q[i].r);
            q[i].id = i;
        }
        sort(q, q + m, cmp);
        for (int i = 0; i < m; i++) {
            for (int j = pos; j <= q[i].r; j++) {
                if (s[j - 1] == '(') {
                    st.push(j);
                } else if (s[j - 1] == ')') {
                    if (!st.empty()) {
                        int tt = st.top();
                        update(tt, 2);
                        st.pop();
                    }
                }
            }
            pos = q[i].r + 1;
            ans[q[i].id] = sum(q[i].r) - sum(q[i].l - 1);
        }
        for (int i = 0; i < m; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
