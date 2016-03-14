#include<stdio.h>
int main()
{
	long long int mid,m,n,a[100005],i,t,p,sum=0,l,r,b[100005];
	scanf("%lld %lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	l=1;
	r=sum+n;
	while(l<r)
	{
	//	printf("%lld %lld\n",l,r);
		for(i=0;i<n;i++)
			b[i]=a[i];
		p=n-1;
		for(i=0;i<m;i++)
		{
			mid=(l+r)/2;
			while(b[p]==0 && p>=0)
				p--;
			mid-=p+1;
			while(p>=0 && mid>=b[p])
			{
				mid-=b[p];
				p--;
			}
			if(p>=0)
				b[p]-=mid;
		}
		if(p<0)
			r=(l+r)/2;
		else
			l=(l+r)/2+1;
	}
	printf("%lld\n",r);
	return 0;
}