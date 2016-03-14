#include <cstdio>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        int total;
        scanf("%d", &total);

        unordered_map<int, int> count;
        count.clear();
        int max_len = -1, start = 1;

        int data[total + 1];
        for (int i = 1; i <= total; i++)
            scanf("%d", &data[i]);

        for (int i = 1; i <= total; i++) {
            // a little like KMP, but without the fail function
            int cur = data[i];
            if (count[cur] == 0)
                count[cur] = i;
            else {
                max_len = max(i - start, max_len);
                start = count[cur] + 1;
                count.clear();
                i = start - 1; // i increments after this round @@
            }
        }

        max_len = max(total + 1 - start, max_len);

        printf("%d\n", max_len);
    }

    return 0;
}
