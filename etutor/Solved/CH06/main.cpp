#include <cstdio>
#include <cmath>

using namespace std;

#define EPS 1e-9

int main()
{
    double hip, height;
    while (scanf("%lf %lf", &hip, &height) == 2) {
        double res = hip / pow(height, 1.5) - 18;

        if (res - 40 > -EPS)
            printf("morbidly obese\n");
        else if (res - 30 > -EPS)
            printf("obese\n");
        else if (res - 25 > -EPS)
            printf("overweight\n");
        else if (res - 18.5 > -EPS)
            printf("healthy\n");
        else
            printf("underweight\n");
    }

    return 0;
}
