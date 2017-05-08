#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int nk[1005];
int lp[1005];
int n;
int ans;

void getpath(int i) {
    set<int> s;
    while (true) {
        if (s.count(i)) break;
        s.insert(i);
        i = nk[i];
    }
    lp[i] = max(lp[i],sz(s));

    // calc the cycle
    int len = 1;
    for (int j = nk[i]; j != i; j = nk[j]) {
        len++;
    }
    ans = max(ans,len);
}


int main() {
    int T; scanf("%d", &T);
    FO(Z,1,T+1) {
        scanf("%d", &n);
        FO(i,0,n) scanf("%d", nk+i+1);
        FO(i,0,n) lp[i+1] = 0;
        ans = 0;
        FO(i,1,n+1) getpath(i);
        int res2 = 0;
        FO(i,1,n+1) if (nk[nk[i]] == i) {
            res2 += lp[i];
            if (i < nk[i]) res2 -= 2;
        }
        ans = max(ans,res2);
        printf("Case #%d: %d\n", Z, ans);
    }
}

