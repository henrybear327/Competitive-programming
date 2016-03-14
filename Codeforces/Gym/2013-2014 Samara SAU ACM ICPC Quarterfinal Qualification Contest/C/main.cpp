#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

int main()
{
    int cnt;
    long long int target;
    while (scanf("%d %I64d", &cnt, &target) == 2) {
        unordered_map<long long int, long long int> DP_map;

        long long int sum_so_far = 0;
        DP_map[sum_so_far] = 1; // think of the way you create prefix sum table, there will be one value, 0, in the very beginning.
        long long int ans = 0;
        for (int i = 0; i < cnt; i++) {
            long long int tmp;
            scanf("%I64d", &tmp);
            sum_so_far += tmp;
            if (DP_map.find(sum_so_far - target) != DP_map.end()) {
                ans += DP_map[sum_so_far - target];
            }

            if (DP_map.find(sum_so_far) != DP_map.end())
                DP_map[sum_so_far]++;
            else
                DP_map[sum_so_far] = 1;
        }

        printf("%I64d\n", ans);
    }

    return 0;
}
