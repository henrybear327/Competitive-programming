#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    vector<ii> inp;
    for(int i = 0; i < n; i++) {
        int price, quality;
        scanf("%d %d", &price, &quality);

        inp.push_back(ii{price, quality});
    }
    sort(inp.begin(), inp.end());

    for(int i = 0; i < n - 1; i++) {
        if(inp[i].second <= inp[i + 1].second)
            continue;
            
        printf("Happy Alex\n");
        return 0;
    }

    printf("Poor Alex\n");

    return 0;
}
