#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define EPS 1e-15

#define double long double

int main()
{
    int A1,B1,A2,B2;
    scanf("%d %d %d %d",&A1,&B1,&A2,&B2);
    if(A1 * B1 < A2 * B2)
    {
        int temp;
        temp = A1;
        A1 = A2;
        A2 = temp;
        temp = B1;
        B1 = B2;
        B2 = temp;
    }
    if(max(A1,B1) >= max(A2,B2) && min(A1,B1) >= min(A2,B2))
    {
        printf("Yes\n");
        return 0;
    }

    ll a = max(A1, B1);
    ll b = min(A1, B1);
    ll c = min(A2, B2);
    ll d = max(A2, B2);

    if(c > b || c > a) {
        printf("No\n");
        return 0;
    }


    double x1 = ( sqrt(   (double)(b * b * c * c * c * c - (d * d + c * c) * (b * b * c * c - c * c * d * d))   ) + (double)b * c * c ) / (double)(d * d + c * c);
    double x2 = ( -sqrt(  (double)(b * b * c * c * c * c - (d * d + c * c) * (b * b * c * c - c * c * d * d))   ) + (double)b * c * c ) / (double)(d * d + c * c);

    if(x1 < x2)
        swap(x1, x2);

    double y = sqrt( (double)(c * c - x1 * x1) );
    double z = sqrt( (double)(d * d - (b - x1) * (b - x1)) );
    if(-EPS <= (double)a - (y + z)) {
        if( x1 >= -EPS  && (double)b - x1 >= -EPS  )
            printf("Yes\n");
        else
            printf("No\n");
    } else {
        y = sqrt( (double)(c * c - x2 * x2) );
        z = sqrt( (double)(d * d - (b - x2) * (b - x2)) );

        if( -EPS <= (double)a - (y + z) && x2 >= -EPS && (double)b - x2 >= -EPS  )
            printf("Yes\n");
        else
            printf("No\n");
    }


    return 0;
}