#include <cstdio>
#include <map>

using namespace std;

int main()
{
    long long int days;
    while (scanf("%lld", &days) == 1 && days) {
        map<long long int, long long int> counter;
        long long int ans = 0;
        while (days--) {
            long long int cnt;
            scanf("%lld", &cnt);
            for (int i = 0; i < cnt; i++) {
                long long int curr;
                scanf("%lld", &curr);

                counter[curr]++;
            }

            long long int max = counter.rbegin()->first, min = counter.begin()->first;
            ans += (max - min);

            if (counter[max] == 1)
                counter.erase(max);
            else
                counter[max]--;

            if (counter[min] == 1)
                counter.erase(min);
            else
                counter[min]--;
        }

        printf("%lld\n", ans);
    }

    return 0;
}