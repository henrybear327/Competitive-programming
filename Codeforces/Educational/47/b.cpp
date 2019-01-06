#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    char inp[100010];
    scanf("%s", inp);
    
    // find first 2
    int sz = strlen(inp);
    int firstTwo = -1;
    for(int i = 0; i < sz; i++) {
        if(inp[i] == '2') {
            firstTwo = i;
            sort(inp, inp + i);
            break;
        }
    }   

    if(firstTwo == -1) {
        sort(inp, inp + sz);
        printf("%s", inp);
    } else {
        // move all 1s to front
        int one = 0;
        for(int i = firstTwo; i < sz; i++)
            if(inp[i] == '1')
                one++;
        
        char ans[100010];
        strcpy(ans, inp);

        for(int i = 0; i < one; i++)
            ans[i + firstTwo] = '1';

        int idx = firstTwo + one;
        for(int i = firstTwo; i < sz; i++) {
            if(inp[i] != '1')
                ans[idx++] = inp[i];
        }
        printf("%s", ans);
    }

    return 0;
}
