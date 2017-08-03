#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n, m, k;
    while(scanf("%d %d %d", &n, &m, &k) == 3) {
        map<int, int> cnt;
        int tmp;
        for(int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            cnt[tmp]++;
        }
        
        for(int i = 0; i < m; i++) {
            scanf("%d", &tmp);
            cnt[tmp]++;
        }
        
        for(int i = 0; i < k; i++) {
            scanf("%d", &tmp);
            cnt[tmp]++;
        }
        
        vector<int> ans;
        for(auto i : cnt)
            if(i.second > 1)
                ans.push_back(i.first);
        
        printf("%d\n", (int)ans.size());
        for(auto i : ans)
            printf("%d\n", i);
    }
}

int main()
{
    solve();

    return 0;
}
