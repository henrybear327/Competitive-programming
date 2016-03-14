#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int rep, rank;
} Node;

int tot;
Node data[1000];

void init_set()
{
    for (int i = 0; i <= tot; i++) {
        data[i].rep = i;
        data[i].rank = 0;
    }
}

int find_set(int a)
{
    /*
    if (data[a].rep == a)
        return a;
    return data[a].rep = find_set(data[a].rep);
    */
    return data[a].rep == a ? a : (data[a].rep = find_set(data[a].rep));
}

bool is_same_set(int a, int b)
{
    return find_set(a) == find_set(b);
}

void union_set(int a, int b)
{
    // data[b].rep = data[a].rep;
    // test case c 1 4, c 2 4 will get you wrong answer
    if (!is_same_set(a, b)) {
        int x = find_set(a), y = find_set(b);
        if (data[x].rank > data[y].rank)
            data[y].rep = x;
        //要改rep的rep，不是路徑上的點的rep，因為這種find_set query是單向的!
        else
            data[x].rep = y;

        if (data[x].rank == data[y].rank) {
            data[y].rank++;
        }
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);
    getchar();
    getchar();

    // int index= 1;
    while (cases--) {
        // printf("Case %d:\n", index++);

        scanf("%d", &tot);
        getchar();
        init_set();

        char query[1000];

        int ans = 0, ans1 = 0;
        while (fgets(query, 1000, stdin) != NULL && query[0] != '\n') {
            char command;
            int a, b;
            sscanf(query, "%c %d %d", &command, &a, &b);

            if (command == 'c') {
                // union
                union_set(a, b);
            } else {
                // check
                if (is_same_set(a, b))
                    ans++;
                else
                    ans1++;
            }

            /*
            for(int i = 1; i <= tot; i++)
                printf("%d ", data[i].rep);
            printf("\n");
            */
        }
        printf("%d,%d\n", ans, ans1);
        if (cases)
            printf("\n");
    }

    return 0;
}
