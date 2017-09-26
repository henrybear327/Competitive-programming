#include <bits/stdc++.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    char inp[111];
    scanf("%s", inp);

    int cnt[26] = {0};
    int len = strlen(inp);
    for(int i = 0; i < len; i++)
        cnt[inp[i] - 'a']++;

    bool ok = true;
    for(int i = 0; i < 26; i++)
        if(cnt[i] > k)
            ok = false;
    printf("%s\n", ok ?"YES" : "NO");

    return 0;
}
