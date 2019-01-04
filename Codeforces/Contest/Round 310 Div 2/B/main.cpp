#include <cstdio>
#include <cstdlib>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main()
{
    int cases;
    scanf("%d", &cases);

    int array[cases];
    for (int i = 0; i < cases; i++)
        scanf("%d", &array[i]);

    int rot = cases - array[0];

    int i;
    for (i = 0; i < cases; i++) {
        if (i % 2 == 1) {
            array[i] = array[i] - rot >= 0 ? array[i] - rot : array[i] - rot + cases;
            if (array[i] != i)
                break;
        } else {
            array[i] =
                array[i] + rot >= cases ? array[i] + rot - cases : array[i] + rot;
            if (array[i] != i)
                break;
        }
    }

    if (i == cases)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
