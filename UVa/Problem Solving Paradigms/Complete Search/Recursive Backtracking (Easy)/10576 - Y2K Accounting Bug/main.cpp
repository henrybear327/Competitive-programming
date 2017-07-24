// enumeration

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s, d;
    while(scanf("%d %d", &s, &d) == 2) {
        int mx = -1;
        
        for(int i = 0; i < (1 << 12); i++) {
            bool surplus[12];
            for(int j = 0; j < 12; j++)
                if((i >> j) & 1)
                    surplus[j] = true;
                else
                    surplus[j] = false;
            
            int sum = 0;
            for(int j = 0; j < 5; j++)
                sum += surplus[j] ? s : -d;
            if(sum >= 0)
                continue;
            
            bool ok = true;
            for(int j = 5; j < 12; j++) {
                sum -= surplus[j - 5] ? s : -d;
                sum += surplus[j] ? s : -d;
                
                if(sum >= 0) {
                    ok = false;
                    break;
                }
            }
            
            if(ok) {
                int tmp = 0;
                for(int j = 0; j < 12; j++) 
                    tmp += surplus[j] ? s : -d;
                
                mx = max(mx, tmp);
            }
        }
        
        if(mx == -1)
            printf("Deficit\n");
        else
            printf("%d\n", mx);
    }
    
    return 0;
}