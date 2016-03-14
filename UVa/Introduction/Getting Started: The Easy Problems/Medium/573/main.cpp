#include <cstdio>

int main()
{
    int height, slides;
    double climb, factor;
    while (scanf("%d %lf %d %lf", &height, &climb, &slides, &factor) == 4 &&
           height != 0) {
        int day = 0;
        double curr = 0, climb_decrease = climb * (factor / 100);
        while (curr <= height && curr >= 0) {
            day++;
            curr = curr + climb;
            // printf("day %d, climb %f, curr %f\n", day, climb, curr);
            if (curr > height)
                break;
            curr -= slides;
            climb = climb - climb_decrease > 0 ? climb - climb_decrease : 0;
            // printf("day %d, climb %f, curr %f\n", day, climb, curr);
        }

        if (curr > height)
            printf("success on day %d\n", day);
        else
            printf("failure on day %d\n", day);
    }

    return 0;
}
