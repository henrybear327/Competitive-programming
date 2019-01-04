#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

#define EPS 1e-9
int main()
{
	/*
	One crucial observation is: all student must spend the same amount of time on bus, 
	or the last student to arrive will have a loonger time than the optimal solution.
	
	p = how many group to be taken by bus ( (n - 1) / k + 1)
	t1 = time on foot
	t2 = time on bus
	t3 = time between the bus drop off the student and pick up anther group of student

	--------> t2 * v2 (by bus)
	      <-- t3 * v2 (bus return)
	      --------> t2 * v2 (another group by bus)
	-----> (on foot) (t2 + t3) * v1
	
	
	t2 * v2 * p - t3 * v2 * (p - 1) = l
	t1 * v1 + t2 * v2 = l
	(t2 + t3) * v1 + t3 * v2 = t2 * v2

	Solve the equations, you can get t1, t2, t3 from them.
	*/
    ll n, l, v1, v2, k;
    scanf("%lld %lld %lld %lld %lld", &n, &l, &v1, &v2, &k);
	
	// ll p = n / k + (n % k == 0 ? 0 : 1);
	ll p = (n - 1) / k + 1;
	double t3 = (double)((v2 - v1) * l) / (double)(v2 * p * (v1 + v2) + (v1 - v2) * v2 * (p - 1));
	double t2 = (double)(l + t3 * v2 * (p - 1)) / (v2 * p);
	double t1 = (double)(l - t2 * v2) / v1;
	
	printf("%.15f\n", t1 + t2);
	
    return 0;
}
