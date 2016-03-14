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
        while (1) {
            while (!s.empty() && (s.top() == curr_station ||
                                  (int)q[curr_station].size() < queue_capacity)) {
                if (!(s.top() == curr_station)) {
                    q[curr_station].push(s.top());
                } else {
                    total--;
                }

                s.pop();
                ans++;
            }

            if (!total)
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
