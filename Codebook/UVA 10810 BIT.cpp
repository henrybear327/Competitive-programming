#include <bits/stdc++.h>

using namespace std;

#define LIMIT 500100
#define LSB(x) ((x) & (-x))

long long int bit[LIMIT];

void add(int i, int val)
{
    while (i <= LIMIT) {
        bit[i] += val;
        i += LSB(i);
    }
}

int sum(int i)
{
    int ans = 0;
    while (i > 0) {
        ans += bit[i];
        i -= LSB(i);
    }

    return ans;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n) {
        int inp[n + 1], orig[n + 1];
        for (int i = 1; i <= n; i++) {
            scanf("%d", &inp[i]);
            orig[i] = inp[i];
        }

        sort(inp + 1, inp + n + 1);

        /*
        因為數字的範圍很大
        所以我們把答案離散化
        
        按照排列之後的順序
        我們把數字重新給一個編號
        從1開始編起（BIT是從1開始編起的）
        */
        map<int, int> m;
        for (int i = 1; i <= n; i++)
            m[inp[i]] = i; // duplicated key?

        memset(bit, 0, sizeof(bit));

        long long int ans = 0; // Oops
        for (int cnt = 0; cnt < n; cnt++) {
            /*
            BIT所記錄的資料是利用重新編號之後的數列來紀錄
            所以像說
            6 2 8 4
            會被重新編號成
            3 1 4 2

            在BIT中，對於每一個i (就是sum(i) )所要記錄的是目前為止合格的數字有幾個(<= i的數字)

            以剛剛那個數列來說 (6 2 8 4)
            對於第一個數字 3 而言
            cnt = 0, sum(6 對應到 3) = 0
            所以ans += 0 - 0; （代表在3之前沒有大於他的數字）
            之後，在 3 那一格加 1
            
            這很重要，因為這麼做就把bit[i >= 3]的所有數值都都加 1 了！
            （這是BIT的特性，畢竟BIT是拿來算prefix sum的！）

            所以下一次如果我們問到>=3的數字，假設是4好了
            我們會知道已經有一個<=4的數字已經出現
            也就可以反推有幾個不合格的數字出現了！
            */
            ans += cnt - sum(m[orig[cnt + 1]]);
            add(m[orig[cnt + 1]], 1);
        }

        printf("%lld\n", ans);
    }

    return 0;
}
