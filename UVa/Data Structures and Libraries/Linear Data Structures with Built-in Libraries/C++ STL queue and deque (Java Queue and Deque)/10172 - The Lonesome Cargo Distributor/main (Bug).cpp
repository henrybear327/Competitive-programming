#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int station, capacity, queue_capacity;
        scanf("%d %d %d", &station, &capacity, &queue_capacity);

        int total = 0;
        queue<int> q[101];
        for (int i = 1; i <= station; i++) {
            int cnt;
            scanf("%d", &cnt);
            total += cnt;
            while (cnt--) {
                int tmp;
                scanf("%d", &tmp);
                q[i].push(tmp);
            }
        }

        stack<int> s;

        // watch out for the empty and over capacity limit problem
        int curr_station = 1;
        int ans = 0;
        while (1) { // BUG!! When two consecutive identical numbers are in the
            // stack, the first one will be pop() and total--, but the
            // second one
            // will be enqueued if the condition is satisfied.
            bool flag = true;
            while (flag) {
                printf("here!\n");
                if (!s.empty() && s.top() == curr_station) {
                    total--;
                    printf("%d: 1 pop %d\n", curr_station, s.top());
                    s.pop();
                    ans++;
                    // continue;
                } else {
                    flag = false;
                }

                if (!s.empty() && (int)q[curr_station].size() < queue_capacity) {
                    flag = true;
                    q[curr_station].push(s.top());
                    printf("%d: 2 enqueue %d\n", curr_station, s.top());
                    s.pop();
                    ans++;
                    // continue;
                }
                // break;
            }
            if (total == 0)
                break;

            while (!q[curr_station].empty() && (int)s.size() < capacity) {
                s.push(q[curr_station].front());
                q[curr_station].pop();
                ans++;
            }

            ans += 2;
            curr_station = curr_station == station ? 1 : curr_station + 1;
        }

        printf("%d\n", ans);
    }

    return 0;
}
