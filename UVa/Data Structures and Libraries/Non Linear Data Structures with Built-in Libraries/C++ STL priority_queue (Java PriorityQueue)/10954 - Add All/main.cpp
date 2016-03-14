#include <cstdio>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main()
{
    int number;
    while (scanf("%d", &number) == 1 && number) {
        // priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int, vector<int>, cmp> pq;

        for (int i = 0; i < number; i++) {
            int tmp;
            scanf("%d", &tmp);

            pq.push(tmp);
        }

        int ans = 0;
        while (!pq.empty()) {
            int sum = 0;
            for (int i = 0; i < 2; i++) {
                sum += pq.top();
                pq.pop();
            }

            ans += sum;
            if (pq.empty() == true)
                break;
            pq.push(sum);
        }

        printf("%d\n", ans);
    }

    return 0;
}
