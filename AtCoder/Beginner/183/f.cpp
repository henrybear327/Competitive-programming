#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 200010;
int n, inp[N];
struct UFDS {   
    int val[N];
    map<int, int> tmp[N];
    void init() {
        memset(val, -1, sizeof(val));

        for(int i = 0; i < n; i++)
            tmp[i][inp[i]] = 1;
    }

    int find(int x) {
        if(val[x] < 0)
            return x;

        int par = find(val[x]);
        val[x] = par;
        for(auto i : tmp[x])
            tmp[par][i.first] += i.second;
        tmp[x].clear();
        return par;
    }

    int sz(int x, int y) {
        x = find(x);
        return tmp[x][y];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if(x == y)
            return;

        if(val[x] > val[y])
            swap(x, y);
        val[x] += val[y];
        for(auto i : tmp[y])
            tmp[x][i.first] += i.second;
        tmp[y].clear();
        val[y] = x;
    }

    void print() {
        for(int i = 0; i < n; i++) {
            printf("i = %d, %d\n", i, val[i]);
            for(auto j : tmp[i]) {
                printf("%d %d\n", j.first, j.second);
            }
        }
    }
} uf;

int main()
{

    int q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
    }
    uf.init();

    for(int i = 0; i < q; i++) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        x--;
        y--;

        if(op == 1) {
            uf.merge(x, y);
            // uf.print();
        } else {
            printf("%d\n", uf.sz(x, y + 1));
        }
    }

	return 0;
}
