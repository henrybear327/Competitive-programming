#include <cstdio>
#include <cmath>

double area(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double ss(double r, double angle1, double angle2)
{
    return r / tan(angle1 / 2) + r / tan(angle2 / 2);
}

int main()
{
    double a, b, c, r;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &r);

    double big_triangle = area(a, b, c);

    /*
    double S = (a + b + c) / 2;
    double R = big_triangle / S;

    double s = r * S / R;

    double small_triangle = r * s;
    */

    double circle = r * r * 4 * atan(1);

    double a_a = acos((a * a - b * b - c * c) / (-2 * b * c));
    double a_b = acos((b * b - a * a - c * c) / (-2 * a * c));
    double a_c = acos((c * c - a * a - b * b) / (-2 * a * b));

    double a1 = ss(r, a_b, a_c);
    double b1 = ss(r, a_c, a_a);
    double c1 = ss(r, a_b, a_a);
    double small_triangle = area(a1, b1, c1);

    printf("%.15f\n", (big_triangle - small_triangle + circle) / big_triangle);
    // printf("%f\n", big_triangle - small_triangle + r * r * 4 * atan(1));
    return 0;
}
