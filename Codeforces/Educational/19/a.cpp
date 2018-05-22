#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    int cnt = 0, base = 2;
    vector<int> res;
    while(n > 1 && cnt != k) {
        while(n % base == 0) {
            if(cnt == k - 1) {
                res.push_back(n);
                cnt++;
                break;
            }
                
            n /= base;
            cnt++;
            res.push_back(base);
        }
        base++;
    }
    
    if(cnt == k)
        for(auto i : res)
            printf("%d ", i);
    else
        printf("-1");
    
    return 0;
}