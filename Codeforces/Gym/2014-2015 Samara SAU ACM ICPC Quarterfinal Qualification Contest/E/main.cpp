#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <climits> //LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    char input[1000000];
    fgets(input, 1000000, stdin);
    int len = strlen(input) - 1;

    if (len & 1) {
        printf("NO\n");
        return 0;
    }

    vector<int> cnt(26, 0);
    for (int i = 0; i < len; i++) {
        cnt[input[i] - 'a']++;
    }

    sort(cnt.begin(), cnt.end());

    /*
    for(int i = 0; i < 26; i++) {
        printf("%d %d\n", i, cnt[i]);
    }

    printf("%d\n", cnt[25]);
    */

    if (cnt[25] * 2 <= len)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
