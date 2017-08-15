#include<bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-10;
int TCs;
double C;
int N;
double L[12];
int i, x, y;

double Area(double r, double s){
	return 0.25*s*sqrt(4.0*r*r-s*s);
}

double Angle(double r, double s){
	if (abs(r*2.0-s)<EPS) return PI;
	return acos((2.0*r*r-s*s)/(2.0*r*r));
}

int Check(double r, int sign){
	double ang = 0.0;
	for (i=0; i<N-1; i++) ang += Angle(r, L[i]);
	if (sign) ang += 2.0*PI-Angle(r, L[i]);
	else ang += Angle(r, L[i]);
	
	if (sign) return (ang+EPS<2.0*PI);
	return (ang>2.0*PI+EPS);
}

double Compute(){
	double ang = 0.0;
	double r = L[N-1]*0.5;
	int sign;
	
	for (i=0; i<N; i++) ang += Angle(r, L[i]);
	if (abs(ang-2.0*PI)>EPS){
		if (ang+EPS<2.0*PI) sign = 1;
		else sign = 0;
		double xL = L[N-1]*0.5;
		double xR = C;
		while(xL+EPS<xR){
			r = (xL+xR)*0.5;
			if (Check(r, sign)) xL = r;
			else xR = r;
		}
	}
	
	C = C*C*PI;
	for (i=0; i<N; i++) C -= Area(r, L[i]);
	if (sign) C += 2.0*Area(r, L[N-1]);
	return C;
}

int main(){
	scanf("%d", &TCs);
	while(TCs--){
		scanf("%lf%d", &C, &N);
		C /= (2.0*PI);
		for (i=0; i<N; i++) scanf("%lf", &L[i]);
		sort(L, L+N);
		
		printf("%.8lf\n", Compute());
	}
	
	return 0;
}


