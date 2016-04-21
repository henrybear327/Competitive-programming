#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
using namespace std;

typedef long long ll;
vector<ll> num;
vector<string> gen;

ll rToNumber(string x)
{
    // 12345
    ll res = 0;
    for(int i = (int)x.length() - 1; i >= 0; i--) {
	res *= 10;
	res += (x[i] - '0');
    }
    //printf("%s %lld\n", x.c_str(), res);
    return res;
}
ll toNumber(string x)
{
    // 12345
    ll res = 0;
    for(int i = 0; i < (int)x.length(); i++) {
	res *= 10;
	res += (x[i] - '0');
    }
    //printf("%s %lld\n", x.c_str(), res);
    return res;
}

ll pow10[20];
void powgen()
{
    pow10[0] = 1;
    for(int i = 1; i <= 18; i++) {
	pow10[i] = pow10[i - 1] * 10;
    }
}

void init()
{
    gen.push_back("4");
    gen.push_back("7");
    int prev = 0;
    int pos[20] = {0};
    for(int i = 1; i <= 8; i++) {
	int len = gen.size();
	pos[i] = prev; 
	for(int j = 0; prev + j < len; j++) {
	    gen.push_back(gen[prev + j] + "4");
	    gen.push_back(gen[prev + j] + "7");
	}
	pos[i + 1] = len; 
	prev = len;
    }
    pos[10] = 1022;
   /* 
    for(int i = 0; i < gen.size(); i++)
	printf("%d %s %lld %lld\n", i, gen[i].c_str(), toNumber(gen[i]), rToNumber(gen[i]));
    for(int i = 0; i <=10; i++)
	printf("%d\n", pos[i]);
    */

    // odd
    num.push_back(4);
    num.push_back(7);

    for(int i = 1; i <= 8; i++) {
	for(int j = pos[i]; j < pos[i + 1]; j++) {
	    num.push_back(toNumber(gen[j]) * pow10[i + 1] + 4 * pow10[i] + rToNumber(gen[j]));
	    num.push_back(toNumber(gen[j]) * pow10[i + 1] + 7 * pow10[i] + rToNumber(gen[j]));
	}
    }
    
    // even
    for(int i = 1; i <= 9; i++) {
	for(int j = pos[i]; j < pos[i + 1]; j++) {
	    num.push_back(toNumber(gen[j]) * pow10[i] + rToNumber(gen[j]));
	}
    }
}

/*
int lb(int l, int r, ll key) 
{
    int notFound = r;
    while(r - l > 1) {
	int mid = l + (r - l) / 2;
	if(num[mid] == key)
	    return mid;
	else if(num[mid] < key)
	    l = mid;
	else
	    r = mid;
    }
    return num[l] <= key && key < num[r] ? (num[l] == key ? l : r) : (key < num[l] ? l : (key == num[r] ? r : notFound));
}
*/

/*
int ub(int l, int r, ll key) 
{
    int notFound = r;
    while(r - l > 1) {
	// [l, r)
	int mid = l + (r - l) / 2;
	if(num[mid] <= key)
	    l = mid;
	else
	    r = mid;
    }
    return num[l] <= key && key < num[r] ? r : key < num[l] ? l : notFound;
}
*/

int lb(int l, int r, ll key) 
{
    r--;
    while(l < r) {
	int mid = (l + r) / 2;
	if(num[mid] < key)
	    l = mid + 1;
	else
	    r = mid;
    }
    return l;
}

int ub(int l, int r, ll key)
{
    r--;
    while(l < r) {
	int mid = (l + r) / 2;
	if(num[mid] >= key)
	    r = mid;
	else
	    l = mid + 1;
    }
    return r;
}

int rrrr = 0;

int main() 
{
    srand(time(NULL));

    powgen();
    init();
    sort(num.begin(), num.end());
    int ncase = 10000;
    if(rrrr == 0)
	scanf("%d", &ncase);
    
    while(ncase--) {
	ll l, r;
	if(rrrr == 0)
	    scanf("%lld %lld", &l, &r);
	else {
	    l = rand() % 10;
	    r = l + rand() % 10;
	    //printf("%lld %lld\n", l, r);
	}
	
	int lbb = lb(0, num.size(), l);
	int ubb = ub(0, num.size(), r);
	//printf("%d %d\n", ub(0, num.size(), r), (int)(upper_bound(num.begin(), num.end(), r) - num.begin()));
	
	if(rrrr == 0) {
	    /*
	    printf("lb diff %d %d\n", lbb,  (int)(lower_bound(num.begin(), num.end(), l) -  num.begin()));
	    printf("ub diff %d %d\n", ubb, (int)(upper_bound(num.begin(), num.end(), r) -  num.begin()));
	    printf("%d\n", ubb - lbb);
	    */
	    printf("%d\n", (int)(upper_bound(num.begin(), num.end(), r) - lower_bound(num.begin(), num.end(), l)));
	} else {
	    int ans =  (int)(upper_bound(num.begin(), num.end(), r) - lower_bound(num.begin(), num.end(), l));
	    int ans1 =  ubb - lbb;
	    if(ans != ans1)
		printf("%lld %lld %d %d\n", l, r, ans, ans1);
	}
    }

    return 0;
}
