#include <cstdio>
using namespace std;

//http://programming-study-notes.blogspot.tw/2014/03/uva-10608-friends.html
 
int Set[30010]; // Set[i]為i這node的father node,Set最上層的Set[root]=root
int Num[30010];   // 以N[i]為root的Set有幾個element
 
void Set_Initial(int N);
int FindRoot(int x);
void Union(int x, int y);
int FindLargest(int N);
 
int main()
{
    int Case, N, M, A, B;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d", &N, &M);
        Set_Initial(N);
        while (M--) {
            scanf("%d %d", &A, &B);
            Union(A, B);
        }
        printf("%d\n", FindLargest(N));
    }
}
void Set_Initial(int N)
{
    for (int i = 1; i <= N; ++i) {
        Set[i] = i;
        Num[i] = 1;
    }
}
int FindRoot(int x)
{
    if (x == Set[x])
        return x;
    return Set[x] = FindRoot(Set[x]);
}
void Union(int x, int y)
{
    x = FindRoot(x);
    y = FindRoot(y);
 
    if (x != y) {
        Set[x] = y;
        Num[y] += Num[x];
    }
}
int FindLargest(int N)
{
    int Max = 0;
    for (int i = 1; i <= N; ++i)
        if (Num[i] > Max)
            Max = Num[i];
    return Max;
}