#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

typedef struct {
    long long int vol_office, vol_hall, p;
    bool in_line;
} Kids;

Kids inp[4010];
int n, cnt;
void hall(int pos)
{
    long long int vol = inp[pos].vol_hall;
    queue<long long int> q;

    for (int i = pos + 1; i < n; i++) {
        if (inp[i].in_line == false)
            continue;

        inp[i].p -= vol;
        // printf("hall inp[%d] %lld\n", i, inp[i].p);

        if (inp[i].p < 0) {
            cnt--;
            inp[i].in_line = false;
            // printf("i %d\n", i);
            q.push(i);
        }
    }

    while (!q.empty()) {
        // printf("hall %d front %lld\n", pos, q.front());
        hall(q.front());
        q.pop();
    }
}

void office(int pos)
{
    long long int vol = inp[pos].vol_office;
    queue<long long int> q;

    for (int i = pos + 1; vol && i < n; i++) {
        if (inp[i].in_line == false)
            continue;

        inp[i].p -= vol;
        // printf("office inp[%d] %lld\n", i, inp[i].p);
        vol--;

        if (inp[i].p < 0) {
            // printf("office i %d\n", i);
            inp[i].in_line = false;
            cnt--;
            q.push(i);
        }
    }

    while (!q.empty()) {
        // printf("%d front %lld\n", pos, q.front());
        hall(q.front());
        q.pop();
    }
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &inp[i].vol_office, &inp[i].vol_hall, &inp[i].p);
        inp[i].in_line = true;
    }

    cnt = n;
    vector<int> ans;
    while (cnt > 0) {
        for (int i = 0; i < n; i++) {
            if (inp[i].in_line == true) {
                // printf("in %d\n", i);
                inp[i].in_line = false;
                office(i);
                ans.push_back(i);
                cnt--;
                break;
            }
        }
    }

    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%d%c", ans[i] + 1, i == (int)ans.size() - 1 ? '\n' : ' ');
    }

    return 0;
}
