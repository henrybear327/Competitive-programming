#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// http://kuoe0.logdown.com/posts/2011/05/01/poj-2231-moo-volume

// A complete rewrite after reading the source code from the above website

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while(ncase--) {
        int n;
        while (scanf( "%d", &n ) == 1) {
            int pos[n];
            for (int i = 0; i < n; i++)
                scanf("%d", &pos[i]);
                
            sort( pos, pos + n );
            long long int ans = 0;
            for ( int i = 0; i < n - 1; ++i )
                ans += ( long long int )( pos[ i + 1 ] - pos[ i ] ) * ( long long int )( n - 1 - i ) * ( i + 1 );
            printf("%lld\n", ans);
        }
    }
    return 0;
}