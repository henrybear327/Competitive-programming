#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int total;
    scanf("%d", &total);

    int myvote = 0;
    priority_queue<int> pq;
    for (int i = 0; i < total; i++) {
        if (i == 0)
            scanf("%d", &myvote);
        else {
            int tmp;
            scanf("%d", &tmp);
            pq.push(tmp);
        }
    }

    int ans = 0;
    while (pq.top() >= myvote) {
        int tmp = pq.top();
        pq.pop();
        pq.push(tmp - 1);
        myvote++;
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}
