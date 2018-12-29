#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
    }

    int curr_head = 0, ans = 0;
    multiset<int> s;
    for(int i = 0; i < n; i++) {
        s.insert(inp[i]);
        while(*s.rbegin() - *s.begin() > 1) {
            s.erase(s.find(inp[curr_head++]));
            // use the original array to erase the element that's before and out-of-bound
        }
        ans = ans < i - curr_head + 1 ? i - curr_head + 1 : ans;
    }

    printf("%d\n",ans);

    return 0;
}
