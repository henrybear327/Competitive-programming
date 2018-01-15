#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);
    
    int cnt[111] = {0};
    for(int i = 1; i <= n; i++) { // len
        for(int j = 0; j < n; j++) { // starting
            if(j + i <= n) {
                for(int k = j; k < i + j; k++) {
                    cnt[k]++;
                }
            }
        }
    }       
    
    int mx = 0;
    for(int i = 0; i < 111; i++)
        mx = max(mx, cnt[i]);
    printf("%d\n", mx);
	    
    return 0;
}
