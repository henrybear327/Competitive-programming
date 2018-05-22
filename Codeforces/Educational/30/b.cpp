#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int len;
    char inp[100010];
    scanf("%d", &len);
    scanf("%s", inp + 1); // case 01101010
        
    int sum = 0;
    map<int, int> loc;
    int ans = 0;
    loc[0] = 0;
    for(int i = 1; i <= len; i++) {
        if(inp[i] == '1')
            sum++;
        else
            sum--;
        
        auto it = loc.find(sum);
        if(it != loc.end()) {
            ans = max(ans, i - it->second);
        } else {
            loc[sum] = i;
        }
    }
    printf("%d\n", ans);

    return 0;
}
