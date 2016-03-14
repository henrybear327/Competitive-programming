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
    return data[a].rep == a ? a : (data[a].rep = find_set(data[a].rep));
}

bool is_same_set(int a, int b)
{
    return find_set(a) == find_set(b);
}

void union_set(int a, int b)
{
    if (!is_same_set(a, b)) {
        int x = find_set(a), y = find_set(b);
        if (data[x].rank > data[y].rank)
            data[y].rep = x;
        else
            data[x].rep = y;

        if (data[x].rank == data[y].rank) {
            data[y].rank++;
        }
    }
}

int main()
{

    return 0;
}
