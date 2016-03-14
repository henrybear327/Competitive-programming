#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
    int number;
    while (scanf("%d", &number) == 1 && number) {
        queue<int> cards;
        for (int i = 1; i <= number; i++) {
            cards.push(i);
        }

        if (number == 1) {
            printf("Discarded cards:\n");
            printf("Remaining card: 1\n");
            continue;
        }
        printf("Discarded cards:");
        while (cards.size() > 2) {
            printf(" %d,", cards.front());
            cards.pop();
            int front = cards.front();
            cards.pop();
            cards.push(front);
        }

        printf(" %d\n", cards.front());
        cards.pop();
        printf("Remaining card: %d\n", cards.front());
    }

    return 0;
}
