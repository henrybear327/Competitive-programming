#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<ii> inp;
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        inp.push_back(ii(a, b)); // room , floor
    }
    
    set<int> ans;
    for(int sz = 1; sz <= 100; sz++) {
        bool ok = true;
        for(auto cur : inp) {
            int room = cur.first;
            int floor = cur.second;

            int suppose = room / sz + 1;

            if(floor != suppose)
                ok = false;
        }

        if(ok == false)
            continue;

        ans.insert((n - 1) / sz);
    }

    if(ans.size() != 1)
        printf("-1\n");
    else
        printf("%d\n", *(ans.begin()) + 1);

    return 0;
}
