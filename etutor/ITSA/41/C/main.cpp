#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct data {
    int x, y, d;
} Data;

bool cmp(const Data &a, const Data &b)
{
    return a.d < b.d;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<Data> inp;
    for (int i = 0; i < n; i++) {
        Data tmp;
        scanf("%d %d %d", &tmp.x, &tmp.y, &tmp.d);
        inp.push_back(tmp);
    }

    sort(inp.begin(), inp.end(), cmp);

    for (int i = 0; i < n; i++)
        printf("%d %d %d\n", inp[i].x, inp[i].y, inp[i].d);

    return 0;
}
