//https://timbian.wordpress.com/2015/02/27/uva-1235-anti-brute-force-lock/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
 
const int MAXN = 501;
const int INF = 10000;
 
int key[MAXN];
int cost[MAXN][MAXN];
int dist[MAXN];
bool vst[MAXN];
 
int abs(int x)
{
    if(x < 0) return -x;
    else return x;
}
 
int compute(int Key1, int Key2)
{
    int d1, d2;
    int roll = 0;
    int dif;
     
    for(int k = 1; k <= 4; k++)
    {
        d1 = Key1 % 10, d2 = Key2 % 10;
        dif = abs(d1 - d2);
        roll += min(dif, 10 - dif);
        Key1 /= 10, Key2 /= 10;
    }
     
    return roll;
}
 
int main()
{
    int test;
    int n;
    int total;
     
    cin >> test;
    while(test--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> key[i];
         
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                cost[i][j] = cost[j][i] = compute(key[i], key[j]);
             
         
        for(int i = 1; i <= n; i++)
        {
            dist[i] = INF;
            vst[i] = false;
        }
         
        total = INF;
        for(int i = 1; i <= n; i++)
            total = min(total, compute(0000, key[i]));
         
         
        dist[1] = 0;
         
        int min, now;
        for(int k = 1; k <= n; k++)
        {
            min = INF;
            for(int i = 1; i <= n; i++)
            {
                if(!vst[i] && dist[i] < min)
                {
                    min = dist[i];
                    now = i;
                }
            }
             
            dist[now] = 0;
            vst[now] = true;
     
            for(int i = 1; i <= n; i++)
            {
                if(!vst[i] && cost[now][i] < dist[i])
                {
                    dist[i] = cost[now][i];
                }
            }
             
            total += min;
        }
         
        cout << total << endl;
    }
 
 
    return 0;
}