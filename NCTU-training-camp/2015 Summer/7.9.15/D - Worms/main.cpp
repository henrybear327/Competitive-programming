#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

// exist O(1) solution
// DP the index of the upper and lower bound!

int binary_search(int key, int worms_in_piles[], int L, int R)
{
    // printf("%d %d %d\n", key, L, R);
    if (L + 1 == R) {
        if (worms_in_piles[L] < key)
            return L + 1;
        else
            return L;
    }
    if (R - 1 == L) {
        if (worms_in_piles[L] < key)
            return L;
        else
            return L + 1;
    }
    int mid = (L + R) / 2;
    if (worms_in_piles[mid] < key)
        return binary_search(key, worms_in_piles, mid, R);
    else if (worms_in_piles[mid] > key)
        return binary_search(key, worms_in_piles, L, mid);
    else
        return mid;
}

int main()
{
    int piles;
    while (scanf("%d", &piles) == 1) {
        int worms_in_piles[piles];
        for (int i = 0; i < piles; i++) {
            scanf("%d", &worms_in_piles[i]);
            if (i > 0)
                worms_in_piles[i] += worms_in_piles[i - 1];
        }

        int juicy_count;
        scanf("%d", &juicy_count);
        for (int i = 0; i < juicy_count; i++) {
            int temp;
            scanf("%d", &temp);
            // printf("Call\n");
            printf("%d\n", binary_search(temp, worms_in_piles, 0, piles - 1) + 1);
        }
    }

    return 0;
}