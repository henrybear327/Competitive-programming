#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>

//taking more memory space than using find(), because [] will create new element if the accessed one doesn't exist!

using namespace std;

int main()
{
    int cnt;
    long long int target;
    while (scanf("%d %I64d", &cnt, &target) == 2) {
        unordered_map<long long int, long long int> DP_map;

        long long int sum_so_far = 0;
        DP_map[sum_so_far] = 1;
        long long int ans = 0;
        for (int i = 0; i < cnt; i++) {
            long long int tmp;
            scanf("%I64d", &tmp);
            sum_so_far += tmp;
            if (DP_map[sum_so_far - target] > 0) {
                ans += DP_map[sum_so_far - target];
            }

	    DP_map[sum_so_far]++;
        }

        printf("%I64d\n", ans);
    }

    return 0;
}
