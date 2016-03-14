#include <bits/stdc++.h>
#define fi first
#define sc second
using namespace std;
typedef pair<int,int> pi;

char s[300009];
char ch[30];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    scanf("%s",s);
    for(int i=0;i<26;i++)ch[i]=i+'a';
    for(int i=0;i<m;i++){
        char a,b;scanf(" %c %c",&a,&b);
        for(int j=0;j<26;j++){
            if(ch[j]==a)ch[j]=b;
            else if(ch[j]==b)ch[j]=a;
        }
    }
    for(int i=0;i<n;i++){
        printf("%c",ch[s[i]-'a']);
    }
}
