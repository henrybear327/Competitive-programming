// http://codeforces.com/problemset/problem/236/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char inp[111];
    scanf("%s", inp);
    
    int len = strlen(inp);
    int cnt[26] = {0};
    for(int i = 0; i < len; i++)
        cnt[inp[i] - 'a']++;
    
    int total = 0;
    for(int i = 0 ; i < 26; i++)
        if(cnt[i])
            total++;
    
    if(total % 2 == 1)
        printf("IGNORE HIM!\n");
    else
        printf("CHAT WITH HER!\n");
    
    return 0;
}