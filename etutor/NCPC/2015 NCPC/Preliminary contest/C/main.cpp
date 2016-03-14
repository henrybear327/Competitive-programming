#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int a,b,c;
    int idx;
} student;

bool cmp(student a,student b)
{
    if(a.a == b.a) {
        if(a.b == b.b) {
            return b.c < a.c;
        }
        return b.b < a.b;
    }
    return b.a < a.a;
}

int table[100000];

int main()
{
    int N,S,K,M,A,B;
    int test_case;
    while(scanf("%d",&test_case)!=EOF) {
        while(test_case--) {
            memset(table,0,sizeof(table));
            scanf("%d%d%d%d%d%d",&N,&S,&K,&M,&A,&B);
            student a[N];
            int temp;
            for(int i=0; i<N; i++) {
                a[i].idx =  i+1;
                a[i].a = 0;
                a[i].b = 0;
                a[i].c = 0;
                for(int j=0; j<K; j++) {
                    scanf("%d",&temp);
                    if(temp>=A) {
                        a[i].a++;
                    } else if(temp>=B && temp<A) {
                        a[i].b++;
                    } else
                        a[i].c++;
                }
            }
            /*for(int i=0; i<N; i++) {
                printf("%d %d %d\n",a[i].a,a[i].b,a[i].c);
            }*/
            sort(a,a+N,cmp);
            /*for(int i=0; i<N; i++) {
                printf("%d ",a[i].idx);
            }
            printf("\n");*/
            int cnt=0;
            int flag=0;
            for(int i=0; i<N; i++) {
                table[a[i].idx] = cnt;
                if(i<N && a[i].a == a[i+1].a && a[i].b == a[i+1].b && a[i].c == a[i+1].c ) {
                    flag = 1;
                } else if(i<N && flag) {
                    cnt = i+1;
                } else
                    cnt++;
            }
            int S_case;
            for(int i=0; i<S; i++) {
                scanf("%d",&S_case);
                printf("%d%c",table[S_case], i == S - 1 ? '\n' : ' ');
            }
        }
    }

    return 0;
}
