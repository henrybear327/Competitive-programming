#include <cstdio>

#define MAX_COST 100000000
int main()
{
    int people, budget, weekend, hotel;
    while (scanf("%d %d %d %d", &people, &budget, &hotel, &weekend) == 4) {
        int min_cost = MAX_COST;

        for (int i = 0; i < hotel; i++) {
            int price;
            scanf("%d", &price);

            for (int i = 0; i < weekend; i++) {
                int vacancy;
                scanf("%d", &vacancy);

                if (vacancy >= people && price * people <= budget)
                    min_cost = (price * people) < min_cost ? (price * people) : min_cost;
            }
        }

        if (min_cost == MAX_COST)
            printf("stay home\n");
        else
            printf("%d\n", min_cost);
    }

    return 0;
}
