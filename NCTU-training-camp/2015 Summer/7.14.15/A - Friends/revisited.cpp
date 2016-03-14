#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

int citizen[30001];

void init()
{
    for (int i = 0; i < 30001; i++)
        citizen[i] = i;
}

int find(int x)
{
    if (citizen[x] == x)
        return x; // x is the leader
    return citizen[x] = find(citizen[x]);
}

void unionxy(int x, int y)
{
    // modify the root value!
    citizen[find(x)] = find(y);
    citizen[x] = find(x);
}

int main()
{
    init();

    int test_cases;
    scanf("%d", &test_cases);
    int count = 0;
    while (test_cases--) {
        init();
        // printf("%d+++++\n", count++);
        int people, pair;
        scanf("%d %d", &people, &pair);
        // printf("%d %d\n", people, pair);

        while (pair--) {
            int a, b;
            scanf("%d %d", &a, &b);
            // printf("%d %d\n", a, b);
            unionxy(a, b);
        }

        int max = 0;
        int count[30001] = {0};
        for (int i = 1; i <= people; i++) {
            find(i);
            // printf("%d ", citizen[i]);
            count[citizen[i]]++;
            if (count[citizen[i]] > max)
                max = count[citizen[i]];
        }
        // printf("\n");
        printf("%d\n", max);
    }
    return 0;
}
