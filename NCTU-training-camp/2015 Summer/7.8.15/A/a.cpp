#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    int N;
    bool need_newline = false;
    while (scanf("%d", &N) == 1) {
        if (N == 0) {
            break;
        }

        while (1) {
            if (need_newline) {
                printf("\n");
                need_newline = false;
            }

            int data[N];
            scanf("%d", &data[0]);
            if (data[0] == 0) {
                need_newline = true;
                break;
            }
            for (int i = 1; i < N; i++) {
                scanf("%d", &data[i]);
            }

            int i = 0, index = 1;
            stack<int> station;
            bool flag = true;
            while (index <= N) {
                if (data[i] == index) {
                    index++;
                    i++;
                } else if (data[i] == (station.size() == 0 ? -1 : station.top())) {
                    station.pop();
                    i++;
                } else {
                    station.push(index++);
                }
            }

            while (i < N) {
                if (data[i] == station.top()) {
                    station.pop();
                    i++;
                } else {
                    flag = false;
                    break;
                }
            }

            if (flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    printf("\n");
    return 0;
}