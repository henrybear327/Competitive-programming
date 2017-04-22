#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int num[1000001];

int main()
{
    int cnt = 1;
    while (scanf("%d", &num[cnt]) == 1)
        cnt++;
    cnt--;

    sort(num + 1, num + cnt + 1);
    printf("%d\n", cnt % 2 == 0 ? num[cnt / 2] : num[(cnt + 1) / 2]);
}