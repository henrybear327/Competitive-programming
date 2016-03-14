#include <cstdio>
#include <cstdlib>
#include <map>
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    long long int total, ratio;
    scanf("%lld %lld", &total, &ratio);

    if (total < 3) {
        printf("0\n");
        return 0;
    }

    long long int sequence[total];
    map<long long int, long long int> l, r;
    for (int i = 0; i < total; i++) {
        long long int curr;
        scanf("%lld", &curr);
        sequence[i] = curr;

        if (i == 0)
            l[curr]++;
        else
            r[curr]++;
    }

    long long int ans = 0;
    for (int i = 1; i < total - 1; i++) {
        r[sequence[i]]--;
        long long int l_cnt = 0, r_cnt = 0;
        l_cnt = sequence[i] % ratio == 0 ? l[sequence[i] / ratio] : 0;
        r_cnt = sequence[i] % ratio == 0 ? r[sequence[i] * ratio] : 0;

        ans += (l_cnt * r_cnt);
        l[sequence[i]]++;
    }

    printf("%lld\n", ans);

    return 0;
}
