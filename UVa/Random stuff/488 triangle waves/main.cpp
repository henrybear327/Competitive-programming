#include <cstdio>

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        int amp, freq;
        scanf("%d %d", &amp, &freq);
	
	/*
        if (freq == 0) //WTF??
            continue;
	*/

        for (int i = 1; i <= freq; i++) {
            for (int j = 1; j <= amp; j++) {
                for (int k = 0; k < j; k++)
                    printf("%d", j);
                printf("\n");
            }
            for (int j = amp - 1; j >= 1; j--) {
                for (int k = 0; k < j; k++)
                    printf("%d", j);
                printf("\n");
            }
            if (i != freq)
                printf("\n");
        }

        if (cases)
            printf("\n");
    }

    return 0;
}
