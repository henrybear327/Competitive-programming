#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    int number;
    while (scanf("%d", &number) == 1) {
        bool bad_type[3] = {false}; // stack, queue, pq
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        while (number--) {
            int cmd, inp;
            scanf("%d %d", &cmd, &inp);

            if (cmd == 1) {
                s.push(inp);
                q.push(inp);
                pq.push(inp);
            } else {
                if (s.empty())
                    bad_type[0] = true;
                else if (bad_type[0] == false && s.top() != inp)
                    bad_type[0] = true;
                else
                    s.pop();

                if (q.empty())
                    bad_type[1] = true;
                else if (bad_type[1] == false && !q.empty() && q.front() != inp)
                    bad_type[1] = true;
                else
                    q.pop();

                if (pq.empty())
                    bad_type[2] = true;
                else if (bad_type[2] == false && !pq.empty() && pq.top() != inp)
                    bad_type[2] = true;
                else
                    pq.pop();
            }
        }

        int cnt = 0, type = -1;
        for (int i = 0; i < 3; i++) {
            if (bad_type[i] == false) {
                type = i;
                cnt++;
            }
        }

        const char *ans[3] = {"stack", "queue", "priority queue"};
        if (cnt == 1)
            printf("%s\n", ans[type]);
        else if (cnt > 1)
            printf("not sure\n");
        else
            printf("impossible\n");
    }

    return 0;
}
