#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200100;

struct Data {
    int price;
    int idx;

    Data(int price, int idx)
    {
        this->price = price;
        this->idx = idx;
    }

    bool operator<(const Data &other) const
    {
        return this->price > other.price;
    }
};

bool inStock[MAX_N];
priority_queue<Data> f[3], b[3];

int solve(int c)
{
    c--;

    Data candf(-1, -1), candb(-1, -1);

    while (f[c].size() > 0) {
        Data tmp = f[c].top();
        f[c].pop();

        if (inStock[tmp.idx] == false)
            continue;

        inStock[tmp.idx] = false;
        candf = tmp;
        break;
    }

    while (b[c].size() > 0) {
        Data tmp = b[c].top();
        b[c].pop();

        if (inStock[tmp.idx] == false)
            continue;

        inStock[tmp.idx] = false;
        candb = tmp;
        break;
    }

    if (candf.price == -1 || candb.price == -1) {
        if (candf.price == -1) {
            return candb.price;
        } else {
            return candf.price;
        }
    } else if (candf.price == -1 && candb.price == -1) {
        return -1;
    } else {
        if (candf.price <= candb.price) {
            if (candf.idx != candb.idx) {
                b[c].push(candb);
                inStock[candb.idx] = true;
            }
            return candf.price;
        } else {
            if (candf.idx != candb.idx) {
                f[c].push(candf);
                inStock[candf.idx] = true;
            }
            return candb.price;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int pr[n];
    int fc[n];
    int bc[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &pr[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &fc[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &bc[i]);

    fill(inStock, inStock + MAX_N, 1);
    for (int i = 0; i < n; i++) {
        int c = fc[i];
        c--;
        f[c].push(Data(pr[i], i));

        c = bc[i];
        c--;
        b[c].push(Data(pr[i], i));
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int c;
        scanf("%d", &c);

        printf("%d%c", solve(c), i == m - 1 ? '\n' : ' ');
    }

    return 0;
}
