#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

char inp[3333];

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int len;
bool isOk(int s)
{
    if(s - 2 < 0)
        return true;

    for(int i = s; i >= 0 && i >= s - 2; i--)
        if(isVowel(inp[i]))
            return true;

    return (inp[s] == inp[s - 1]) && (inp[s - 1] == inp[s - 2]);
}

int main()
{
    scanf("%s", inp);
    
    len = strlen(inp);
    vector<int> cut;
    for(int i = 0; i < len; i++) {
        if(isOk(i)) 
            continue;
        
        cut.push_back(i);
        i++;
    }
    
    int idx = cut.size() > 0 ? 0 : -1;
    for(int i = 0; i < len; i++) {
        if(idx >= 0 && i == cut[idx]) {
            printf(" ");
            idx++;
        }
        printf("%c", inp[i]);
    }
    puts("");

    return 0;
}
