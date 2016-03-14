#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> inp;
    int tmp;
    while (scanf("%d", &tmp) != EOF)
        inp.push_back(tmp);
    sort(inp.begin(), inp.end());
    for (int i = 0; i < (int)inp.size(); i++)
        printf("%d\n", inp[i]);
    return 0;
}
