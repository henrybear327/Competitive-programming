#include <bits/stdc++.h>

using namespace std;

void solve(int ncase)
{
    int energy, k;
    scanf("%d %d", &energy, &k);
    
    int team[k];
    for(int i = 0; i < k; i++)
        scanf("%d", &team[i]);
    sort(team, team + k);
    
    int ans = 0;
    int mx = k - 1;
    for(int i = 0; i < k; i++) {
        if(team[i] >= energy) {
            if(mx == i)
                break;
            if(ans == 0)
                break;
            
            energy += team[mx];
            mx--;
            ans--;
        }

        energy -= team[i];
        ans++;
    }

    printf("Case #%d: %d\n", ncase, ans);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    
    for(int i = 0; i < ncase; i++) {
        solve(i + 1);
    }
    
    return 0;
}