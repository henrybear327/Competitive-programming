// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

static int initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

// do the work with the largest quantity first
// ABCABDA..A is better than DABCAB.A..A
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int cnt[26] = {0};
        for (auto i : tasks)
            cnt[i - 'A']++;

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < 26; i++)
            if (cnt[i] > 0)
                pq.push(make_pair(cnt[i], i));

        int tick = 0;
        while (pq.size() > 0) {
            int t = 0;
            queue<pair<int, int>> q;
            while (t <= n && pq.size() > 0) {
                auto cur = pq.top();
                pq.pop();
                cur.first--;
                if (cur.first > 0)
                    q.push(cur);
                t++;
                tick++;
            }

            sort(cnt, cnt + 26);
            if (q.size() > 0) {
                tick += (n + 1 - t);
            }

            while (q.size() > 0) {
                pq.push(q.front());
                q.pop();
            }
        }

        return tick;
    }

    // int leastInterval(vector<char> &tasks, int n)
    // {
    //     int cnt[26] = {0};
    //     for (auto i : tasks)
    //         cnt[i - 'A']++;

    //     sort(cnt, cnt + 26);
    //     int tick = 0;
    //     while (cnt[25] > 0) {
    //         int t = 0;
    //         int i = 25;
    //         while (t <= n && i >= 0) {
    //             if (cnt[i] > 0) {
    //                 cnt[i]--;
    //                 t++;
    //                 tick++;
    //             }

    //             i--;
    //         }

    //         sort(cnt, cnt + 26);
    //         if (i < 0 && cnt[25] > 0) {
    //             tick += (n + 1 - t);
    //         }
    //     }

    //     return tick;
    // }
};

int main()
{
    return 0;
}