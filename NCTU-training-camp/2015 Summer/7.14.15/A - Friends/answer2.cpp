#include <cstdio>
#define MAX(x,y) ((x)>=(y)?(x):(y))

using namespace std;

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--) {
        int people,pair;
        scanf("%d %d",&people,&pair);
        //initialize
        int group[people+1];
        for(int i=1; i<=people; i++) {
            group[i]=i;
        }
        int num_people[people+1];
        //initailize
        for(int i=1; i<=people; i++) {
            num_people[i]=1;
        }

        while(pair--) {
            int x,y;
            scanf("%d %d",&x,&y);
            //優化過 把人數少的set並到人數大多的
            int p,big,samll_group;
            if(num_people[x]<=num_people[y]) {
                p=num_people[x];
                big=group[y];
                samll_group=group[x];
            } else {
                p=num_people[y];
                big=group[x];
                samll_group=group[y];
            }
            for(int i=1; i<=people; i++) {
                if(group[i]==samll_group) {
                    group[i]=big;
                    num_people[samll_group]--;
                    num_people[big]++;
                }
            }
        }
        int max=num_people[1];
        for(int i=2; i<=people; i++) {
            max=MAX(max,num_people[i]);
        }
        printf("%d\n",max);
    }
    return 0;
}