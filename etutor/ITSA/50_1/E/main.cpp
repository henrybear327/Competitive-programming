/*
ax - by = 1
x = (1 + by) / a

5x - 15y = 1

x = (1 + 15y) / 5
*/

#include <cstdio>

int main()
{
 int ncase;
 scanf("%d", &ncase);

  while(ncase--) {
       int a, b;
      scanf("%d %d", &a, &b);

       // check if (1 + by) % a can be 0
      int used[1000] = {0}, flag = 0;
        for(int y = 1; y <= 1000; y++) {
            int val = (1 + b * y) % a;
         if(val == 0) {
             printf("%d %d\n", (1 + b * y) / a, y);
             flag = 1;
             break;
         }
      }

     if(flag == 0)
          printf("No solution!\n"); // stupid **!**
   }

 return 0;
}

/*
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		int a, b;
		scanf("%d %d", &a, &b);

		// check if (1 + by) % a can be 0
		vector< pair<int, int> > ans;
		for(int y = 1; y <= 1000; y++) {
			int val = (1 + b * y) % a;
			if(val == 0) {
				ans.push_back(make_pair((1 + b * y) / a, y));
			}
		}

		if((int)ans.size() == 0)
			printf("No solution!\n");
		else {
			sort(ans.begin(), ans.end());
			if(ans[0].first < ans[1].first && ans[0].second && ans[1].second)
				printf("%d %d\n", ans[0].first, ans[0].second);
			else
				printf("No solution!\n");
		}
	}

	return 0;
}
*/
