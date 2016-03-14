#include <cstdio>
#include <map>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int tmp;
    vector<int> inp;
    map<int, int> cnt;
    while (scanf("%d", &tmp) == 1) {
        inp.push_back(tmp);
        cnt[tmp]++;
    }
    sort(inp.begin(), inp.end());

    if (cnt[inp[inp.size() / 2]] >= (int)inp.size() / 2)
        printf("Majority is %d\n", inp[inp.size() / 2]);
    else
        printf("No Majority\n");

    return 0;
}
