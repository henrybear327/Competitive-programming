#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str[1111111];
    scanf("%s", str);
    int strl = strlen(str);
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char inp[1111];
        scanf("%s", inp);
        
        int len = strlen(inp);
        int start = -1, end = -1, cnt = 0;
        for(int j = 0; j < strl && cnt < len; j++) {
            if(inp[cnt] == str[j]) {
                if(start == -1) 
                    start = j;
                if(cnt == len - 1)
                    end = j;
                
                cnt++;
            }
        }
        
        if(cnt != len) 
            printf("Not matched\n");
        else
            printf("Matched %d %d\n", start, end);
    }
    
    return 0;
}