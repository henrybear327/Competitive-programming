#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);

    int tot = 0;
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if(i < n - k) 
            tot += num;
        else
            tot += x;
    }
    printf("%d\n", tot);
    
    return 0;
}
