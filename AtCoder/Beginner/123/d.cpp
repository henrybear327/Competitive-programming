#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> iii;

// BFS for solution!
// for every move, you can generate 3 more candidates
// you can push the value to a pq!

const int N = 3333;
ll inpX[N], inpY[N], inpZ[N];
struct Node {
    int x, y, z;
    bool operator<(const Node &others) const
    {
        ll s1 = inpX[x] + inpY[y] + inpZ[z];
        ll s2 = inpX[others.x] + inpY[others.y] + inpZ[others.z];

        return s1 < s2;
    }

    ll val()
    {
        return inpX[x] + inpY[y] + inpZ[z];
    }
};

int main()
{
    int x, y, z, k;
    scanf("%d %d %d %d", &x, &y, &z, &k);

    for (int i = 0; i < x; i++)
        scanf("%lld", &inpX[i]);
    sort(inpX, inpX + x);
    for (int i = 0; i < y; i++)
        scanf("%lld", &inpY[i]);
    sort(inpY, inpY + y);
    for (int i = 0; i < z; i++)
        scanf("%lld", &inpZ[i]);
    sort(inpZ, inpZ + z);

    priority_queue<Node> pq;
    set<iii> used;
    used.insert({x - 1, {y - 1, z - 1}});
    pq.push({x - 1, y - 1, z - 1});
    while (pq.size() > 0 && k--) {
        Node cur = pq.top();
        pq.pop();
        printf("%lld\n", cur.val());

        if (cur.x > 0) {
            auto newNode = cur;
            newNode.x--;
            iii c = {newNode.x, {newNode.y, newNode.z}};
            if (used.find(c) == used.end())
                pq.push(newNode), used.insert(c);
        }
        if (cur.y > 0) {
            auto newNode = cur;
            newNode.y--;
            iii c = {newNode.x, {newNode.y, newNode.z}};
            if (used.find(c) == used.end())
                pq.push(newNode), used.insert(c);
        }
        if (cur.z > 0) {
            auto newNode = cur;
            newNode.z--;
            iii c = {newNode.x, {newNode.y, newNode.z}};
            if (used.find(c) == used.end())
                pq.push(newNode), used.insert(c);
        }
    }

    return 0;
}
