// http://codeforces.com/problemset/problem/469/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    set<int> has;
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int num;
        scanf("%d", &num);
        has.insert(num);
    }
    
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int num;
        scanf("%d", &num);
        has.insert(num);
    }
    
    bool ok = true;
    for(int i = 1; i <= n; i++)
        if(has.find(i) == has.end())
            ok = false;

    if(ok)
        printf("I become the guy.\n");
    else
        printf("Oh, my keyboard!\n");
    
    return 0;
}