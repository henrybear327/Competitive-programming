#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);
    
    vector<int> oddp, oddn;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        
        if(tmp >= 0 && tmp % 2 == 0) {
            ans += tmp;
            continue;
        }
        
        if(abs(tmp) % 2 == 1 && tmp > 0)
            oddp.push_back(tmp);
        else if(abs(tmp) % 2 == 1 && tmp < 0)
            oddn.push_back(tmp);
    }
    
    sort(oddp.begin(), oddp.end());
    sort(oddn.begin(), oddn.end());
    
    if(oddp.size() > 0) {
        for(auto i : oddp)
            ans += i;
    } 
    
    if(ans % 2 == 0) {
        if(oddn.size() > 0) {
            if(oddp.size() > 0 && abs(oddn[oddn.size() - 1]) > oddp[0])
                ans -= oddp[0];
            else
                ans += oddn[oddn.size() - 1];
        } else
            ans -= oddp[0];
    } 
    printf("%lld\n", ans);
    
    return 0;
}