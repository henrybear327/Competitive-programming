// http://www.itdadao.com/articles/c15a764547p0.html
//  poj 1741 Tree 点分治

// 题目链接:

//      http://poj.org/problem?id=1741

// 题目大意:

//      给定一棵N(1<=N<=10000)个结点的带权树，定义dist(u,v)为u,v两点间的最短路径长度，
//  路径的长度定义为路径上所有边的权和。再给定一个K(1<=K<=1e9)，如果对于不同的两个
//  结点a,b，如果满足dist(a,b)<=K，则称(a,b)为合法点对。求合法点对个数。

// 解题思路:

//      点分治.首先我们将树转化成有根树,这样点对有两种情况:
//  1)在同一个子树内
//  2)路径经过根节点

//      对于第一种情况,我们进行递归处理,可以转化成第二种情况.
//      对于第二种情况.我们设belong[i] =
//      x(x为根节点的某个儿子,i是在x为根节点的子树内)
//  这样我们要求的就是
//      dist[i] + dist[j] <= K(belong[i] != belong[j])(跨根节点)
//  =   dist[i] + dist[j] <= K(i != j) - (dist[i] + dist[j] <= K(belong[i] ==
//  belong[j])
//  这样,对于前者,我们求以root为根的节点的ans[root],对于后者,答案是root的儿子节点的ans[v]
//  的和.最后结果是ans += ans[root] - (ans[v1] + ans[v2] + ... +
//  ans[vk])(v1..vk为root的
//  儿子).

//      最后,就是这个root如何选择,如果每次暴力以每个节点为root,这样无疑是会超时的.树分治
//  每次以树的重心为root,这样子树的点就会减小一般,所以是log(n),求出点对数也很好做,一遍快排
//  然后O(n)复杂度可以算出.

//      最后总结,求重心,以重心递归,以每个重心算出当前所有点到重心的距离dis,排序算出点对做累
//  加再对重心的每个儿子算出点对做累减.

//  感悟:

//      第一次接触点分治,看了09年漆子超大神的论文,以及各位大神的题解博客,才勉强弄懂,有种兴奋
//  对算法的奥妙有着无穷的神往,不多说啦,加油~~~ ^ _ ^

//  参考材料:

//      http://wenku.baidu.com/view/e087065f804d2b160b4ec0b5.html###(漆子超论文)
//      http://blog.sina.com.cn/s/blog_6d5aa19a0100o73m.html(整体思路)
//      http://blog.csdn.net/woshi250hua/article/details/7723400(明白为何做减法)
//      http://blog.csdn.net/sdj222555/article/details/7893862(参考具体实现)

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000 + 8;

int num;
int head[MAXN];
int siz[MAXN];
int vis[MAXN];
int dis[MAXN];
int root;
int n;
int k;
int mins;
int cnt;
int ans = 0;

struct Edge {
    int to;
    int w;
    int next;

    Edge() {}

    Edge(int to, int w, int next) : to(to), w(w), next(next) {}
} edges[MAXN << 1];

void init()
{
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    num = 0;
    ans = 0;
}

void add_edges(int u, int v, int w)
{
    edges[num] = Edge(v, w, head[u]);
    head[u] = num++;
}

void input()
{
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edges(u, v, w);
        add_edges(v, u, w);
    }
}

void dfssize(int u, int fa)   // 求size[u](以u为根节点的子树节点数目)
{
    siz[u] = 1;

    for (int i = head[u]; i != -1; i = edges[i].next) {
        int v = edges[i].to;
        if (v == fa || vis[v])
            continue;
        dfssize(v, u);
        siz[u] += siz[v];
    }
}

void dfsroot(int u, int fa,
             int tot)   // 求重心(找到除去这个节点,各子树中最大节点数最小)
{
    int maxs = tot - siz[u];

    for (int i = head[u]; i != -1; i = edges[i].next) {
        int &v = edges[i].to;

        if (v == fa || vis[v])
            continue;

        dfsroot(v, u, tot);

        maxs = max(maxs, siz[v]);
    }

    if (maxs < mins) {
        mins = maxs;
        root = u;
    }
}

void dfsdis(int u, int fa, int d)   // 求各个点到重心的距离
{
    dis[cnt++] = d;
    for (int i = head[u]; i != -1; i = edges[i].next) {
        int &v = edges[i].to;
        if (v == fa || vis[v])
            continue;

        dfsdis(v, u, d + edges[i].w);
    }
}

int cal(int u, int d)
{
    cnt = 0;
    dfsdis(u, 0, d);
    sort(dis, dis + cnt);
    int i = 0;
    int j = cnt - 1;
    int res = 0;
    while (i < j) { // O(n)经典算法
        while (i < j && dis[i] + dis[j] > k)
            j--;

        res += j - i;

        i++;
    }
    return res;
}

void dfs(int u)   // 以重心分治
{
    cnt = 0;
    mins = MAXN;
    dfssize(u, 0);
    dfsroot(u, 0, siz[u]);
    ans += cal(root, 0);
    vis[root] = 1;

    for (int i = head[root]; i != -1; i = edges[i].next) {
        int &v = edges[i].to;

        if (!vis[v]) {
            ans -= cal(v, edges[i].w); //  这里减是很微妙的,在参考材料中的第三
            dfs(v); //  中,有一些介绍,"比如1是根,1<-2<-3<-4，
            //  dis(4,1) = 10,dis(3,1) = 5，k = 20,
            //  那么dis(4,1)和dis(3,1)也合法，这显然
            //  不符合逻辑",这句话的理解,让我有些疑惑
        }         //  我想应该这是重复计算了因为dis(3,4)会在
        //  3为根的子树中计算一次,如果在1为根子树
        //  中再次计算,就会重复
    }
}

int main()
{
    // freopen("1.txt","r",stdin);
    while (scanf("%d%d", &n, &k) != EOF && n && k) {
        init();

        input();

        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}
