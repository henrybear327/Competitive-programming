#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    ll ans = 0;
    ll inp[n];
    for(int i = 0; i < n; i++) 
        scanf("%lld", &inp[i]);
    
    map<ll, queue<int>> cnt;
    for(int i = 0; i < k; i++)
        cnt[inp[i]].push(i);
    
    vector<ii> seq;
    for(int i = k; i < n; i++) {
        // printf("%d: %lld %lld\n", i, inp[i], cnt.rbegin()->first);
        if(inp[i] >= cnt.rbegin()->first) {
            seq.push_back(ii(i, i));
            continue;
        }
        
        cnt[inp[i]].push(i);

        ans += (cnt.rbegin()->first) * (i - (cnt.rbegin()->second).front());
        seq.push_back(ii(cnt.rbegin()->second.front(), i));
        (cnt.rbegin()->second).pop();
        if((cnt.rbegin()->second).size() == 0)
            cnt.erase(cnt.rbegin()->first);
    }
    
    int time = n;
    while(cnt.size() > 0) {
        ans += (cnt.rbegin()->first) * (time - (cnt.rbegin()->second).front());
        seq.push_back(ii(cnt.rbegin()->second.front(), time));
        (cnt.rbegin()->second).pop();
        if((cnt.rbegin()->second).size() == 0)
            cnt.erase(cnt.rbegin()->first);
        time++;
    }
    sort(seq.begin(), seq.end());

    printf("%lld\n", ans);
    for(auto i : seq)
        printf("%d ", i.second + 1);

    return 0;
}
