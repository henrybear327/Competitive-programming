// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1508&mosmsg=Submission+received+with+ID+19699079

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int encode(char c)
{
    if('a' <= c && c <= 'z')
        return c - 'a' + 26;
    return c - 'A';
}

char decode(int v)
{
    if(v < 26)
        return v + 'A';
    return v - 26 + 'a';
}

int main()
{
    char str[1111111];
    scanf("%s", str);
    int strl = strlen(str);
    ii pos[52];
    fill(pos, pos + 52, ii(-1, -1));
    
    pos[encode(str[0])].first = 0;
    for(int i = 1; i < strl; i++) {
        if(str[i] != str[i - 1]) {
            pos[encode(str[i - 1])].second = i - 1;
            pos[encode(str[i])].first = i;
        }
    }
    pos[encode(str[strl - 1])].second = strl - 1;
    
    for(int i = 0; i < 52; i++) 
        if(pos[i].first != -1)
            printf("%c %d %d\n", decode(i), pos[i].first, pos[i].second);
    
    // int n;
    // scanf("%d", &n);
    // for(int i = 0; i < n; i++) {
    //     char inp[1111];
    //     scanf("%s", inp);
    //     int len = strlen(inp);
        
        
        
    //     if(cnt != len) 
    //         printf("Not matched\n");
    //     else
    //         printf("Matched %d %d\n", start, end);
    // }
    
    return 0;
}