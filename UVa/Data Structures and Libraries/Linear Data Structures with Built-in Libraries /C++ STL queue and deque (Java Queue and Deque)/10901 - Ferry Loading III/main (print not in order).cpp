#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int limit, transfer_time, query;
        scanf("%d %d %d", &limit, &transfer_time, &query);

        queue<int> left, right;
        for (int i = 0; i < query; i++) {
            int time;
            char side[10];
            scanf("%d %s", &time, side);

            if (side[0] == 'l')
                left.push(time);
            else
                right.push(time);
        }

        int system_time = 0;
        bool at_left = true;
        while (!left.empty() || !right.empty()) {
            int cnt = 0;
            if (at_left && !left.empty()) {
                while (!left.empty() && system_time >= left.front() && cnt <= limit) {
                    cnt++;
                    left.pop();
                }

                if (cnt == 0) {
                    if (right.front() < left.front()) {
                        system_time = right.front() + transfer_time;
                        at_left = !at_left;
                    } else
                        system_time = left.front();
                    continue;
                }

                system_time += transfer_time;
                for (int i = 0; i < cnt; i++)
                    printf("%d\n", system_time);
                at_left = !at_left;
            } else if (!at_left && !right.empty()) {
                while (!right.empty() && system_time >= right.front() && cnt <= limit) {
                    cnt++;
                    right.pop();
                }

                if (cnt == 0) {
                    if (left.front() < right.front()) {
                        system_time = left.front() + transfer_time;
                        at_left = !at_left;
                    } else
                        system_time = right.front();
                    continue;
                }

                system_time += transfer_time;
                for (int i = 0; i < cnt; i++)
                    printf("%d\n", system_time);
                at_left = !at_left;
            } else {
                system_time += transfer_time;
                at_left = !at_left;
            }
        }

        if (cases)
            printf("\n");
    }

    return 0;
}
