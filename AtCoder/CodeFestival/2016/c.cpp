#include <bits/stdc++.h>

using namespace std;

int main()
{
    char inp[111111];
    scanf("%s", inp);
    
    int k;
    scanf("%d", &k);
    
    int len = strlen(inp);
    for(int i = 0; i < len && k > 0; i++) {
        if(inp[i] == 'a') 
            continue;
        
        
        int dist = 'z' - inp[i] + 1;
        if(dist > k)
            continue;
        
        inp[i] = 'a';
        k -= dist;
    }
    
    if(k > 0) {
        k %= 26;
        inp[len - 1] = (inp[len - 1] - 'a' + k) % 26 + 'a';
    }
    
    printf("%s\n", inp);
    
    return 0;
}