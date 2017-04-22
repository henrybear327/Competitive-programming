#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    vector<int> inp;
    int num;
    while (scanf("%d", &num) == 1)
        inp.push_back(num);

    sort(inp.begin(), inp.end());
    int cnt = (int)inp.size();
    printf("%d\n", cnt % 2 == 0 ? inp[cnt / 2 - 1] : inp[(cnt + 1) / 2 - 1]);
}