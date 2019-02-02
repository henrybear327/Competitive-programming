#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    multiset<int> inp;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        inp.insert(num);
    }

    // first number
    {
        int num = *inp.rbegin();
        printf("%d ", num);

        for (int i = 1; i <= num; i++)
            if (auto it = inp.find(i); num % i == 0)
                inp.erase(it);
    }

    {
        // second number
        int num = *inp.rbegin();
        printf("%d ", num);
    }

    return 0;
}
