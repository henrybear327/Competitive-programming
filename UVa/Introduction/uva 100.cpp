#include <cstdio>
//#include <iostream>

using namespace std;

int DP[10000001] = {0};

int result(int num)
{
    if(num > 10000000) {
        if(num & 1)
            return 1 + result(num * 3 + 1);
        return 1 + result(num / 2);
    }

    if(DP[num])
        return DP[num];

    if(num & 1)
        return DP[num] = 1 + result(num * 3 + 1);
    return DP[num] = 1 + result(num / 2);
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int a, b;
    DP[1] = 1;
    while(scanf("%d %d", &a, &b) == 2) {
    //while(cin >> a >> b) {
        printf("%d %d ", a, b);
        //cout << a << " " << b << " ";
        if(a > b) {
            int tmp= a;
            a = b;
            b =tmp;
        }

        int ans = 0;
        for(int i = a; i <=b; i++) {
            ans = result(i) > ans ? result(i):ans;
        }
        printf("%d\n", ans);
        //cout << ans << endl;
    }

    return 0;
}

