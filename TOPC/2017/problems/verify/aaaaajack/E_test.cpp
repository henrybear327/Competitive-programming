#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1);
const double eps=1e-7;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		double c,a[10],tri=0;
		int n,mx=-1;
		bool acute=false;
		scanf("%lf%d",&c,&n);
		for(int i=0;i<n;i++) scanf("%lf",&a[i]),a[i]/=2;
		for(int i=0;i<n;i++){
			if(mx<0||a[i]>a[mx]) mx=i;
		}
		for(int i=0;i<n;i++){
			if(i!=mx) tri+=a[i];
			else tri-=a[i];
		}
		assert(tri>0);
		double ta=0,poly=0;
		for(int i=0;i<n;i++){
			ta+=asin(min(a[i]/a[mx],1.0));
		}
		if(ta>PI) acute=true;
		else acute=false;
		double l=a[mx],r=c/PI/2;
		ta=0;
		for(int i=0;i<n;i++){
			if(i!=mx) ta+=asin(a[i]/r);
		}
		if(acute){
			ta+=asin(a[mx]/r);
			assert(ta-eps<PI);
		}
		else{
			ta+=PI-asin(a[mx]/r);
			assert(ta+eps>PI);
		}
		for(int i=0;i<50;i++){
			double m=(l+r)/2;
			ta=0;
			for(int j=0;j<n;j++){
				if(j!=mx) ta+=asin(a[j]/m);
			}
			if(acute){
				ta+=asin(a[mx]/m);
				if(ta>PI) l=m;
				else r=m;
			}
			else{
				ta+=PI-asin(a[mx]/m);
				if(ta>PI) r=m;
				else l=m;
			}
		}
		for(int i=0;i<n;i++){
			if(i!=mx) poly+=a[i]*sqrt(max(l*l-a[i]*a[i],0.0));
			else if(acute) poly+=a[i]*sqrt(max(l*l-a[i]*a[i],0.0));
			else poly-=a[i]*sqrt(max(l*l-a[i]*a[i],0.0));
		}
		printf("%.10f\n",c*c/PI/4-poly);
	}
	return 0;
}