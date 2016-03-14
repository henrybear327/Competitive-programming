#include <cstdio>
#include <cstdlib>
#include <queue> 

using namespace std;

int main()
{
    int N;
    while(scanf("%d",&N)==1 && N){
        queue<int> deck ;
        for(int i=1;i<=N;i++){
            deck.push(i);
        }
        printf("Discarded cards:");
        int flag=0;
        while(deck.size()>=2){
            int temp1=deck.front();
            if(flag==0)
            printf(" %d",temp1);
            else
            printf(", %d",temp1);
            deck.pop();
            int temp2=deck.front();
            deck.push(temp2);
            deck.pop();
            flag++;
        }
        printf("\n");
       printf("Remaining card: %d\n",deck.front());
    }
    return 0;
}