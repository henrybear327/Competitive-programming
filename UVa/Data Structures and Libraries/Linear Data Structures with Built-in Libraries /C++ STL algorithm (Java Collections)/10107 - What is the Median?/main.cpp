#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

// watch out for the case 1 1 2 2 1 1 2 2 1 1 2 2.......

map<long long int, int> inp;

int main()
{
    long long int curr;
    int total = 0;
    while (scanf("%lld", &curr) == 1) {
        inp[curr]++;
        total++;

        int mid;
        bool is_odd = true;
        if (total & 1) {
            mid = total / 2 + 1;
        } else {
            mid = total / 2;
            is_odd = false;
        }

        int cnt = 0;
        bool flag = false;

        for (auto it = inp.begin(); it != inp.end(); it++) {
            if (cnt + it->second < mid) {
                cnt += it->second;
                continue;
            } else if (cnt + it->second == mid) {
                cnt += it->second;
            } else {
                // do nothing?
            }

            if (is_odd)
                printf("%lld\n", it->first);
            else {
                if (cnt == mid)
                    printf("%lld\n", (it->first + (++it)->first) / 2);
                else
                    printf("%lld\n", it->first);
            }

            flag = true;
            break;
        }

        if (flag == false) {
            auto it = inp.rbegin();
            printf("%lld\n", it->first);
        }
    }

    return 0;
}
