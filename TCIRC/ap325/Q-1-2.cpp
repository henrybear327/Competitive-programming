#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;

typedef long long int ll;

ll solve()
{
    char inp[4 + 3];
    scanf("%s", inp);

    if (inp[0] == 'f') {
        ll x = solve();
        return 2 * x - 3;
    } else if (inp[0] == 'g') {
        ll x = solve();
        ll y = solve();
        return 2 * x + y - 7;
    } else if (inp[0] == 'h') {
        // ll x, y, z;
        // tie(x, y, z) = make_tuple(solve(), solve(), solve()); // function call
        // ordering is not guaranteed for solve()
        ll x = solve();
        ll y = solve();
        ll z = solve();
        return 3 * x - 2 * y + z;
    } else {
        return atoi(inp);
    }
}

int main()
{
    printf("%lld\n", solve());

    return 0;
}
