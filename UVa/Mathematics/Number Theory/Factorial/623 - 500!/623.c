#include <stdio.h>
#define LEN 2600
#define MAX 1000

int Num[MAX+1][LEN] = {0};

//prototype
void Calculate(void);
void Print(int num);

int main()
{
	int num;
	int check;
//freopen("623.in","r",stdin);
	Calculate();
	while(scanf(" %d",&num)!=EOF){
		Print(num);
	}
	return 0;
}

void Calculate(void)
{
	int i, j;
	//initialize array
	for(i=0; i<MAX; i++)
		for(j=0; j<LEN; j++)
			Num[i][j]=0;
	//0! = 1
 	Num[0][0]=1;
	//1! = 1
 	Num[1][0]=1;

	for(i=2; i<=MAX; i++){
		for(j=0; j<LEN; j++) {
			Num[i][j] += Num[i-1][j]*i;
			if(Num[i][j] >= 10) {
				Num[i][j+1] += Num[i][j] / 10;
       				Num[i][j] %= 10;
     			}
		}
	}
}

void Print(int num)
{
	int i;

	printf("%d!\n", num);

	for(i=LEN-1; i>0; i--)
		if(Num[num][i]!=0)
			break;

 	for(; i>=0; i--){
		printf("%d", Num[num][i]);
	}

	printf("\n");

}
