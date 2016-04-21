#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
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

int main() 
{
    powgen();
    init();
    sort(num.begin(), num.end());
    int ncase;
    scanf("%d", &ncase);
    
    while(ncase--) {
	ll l, r;
	scanf("%lld %lld", &l, &r);
	
	printf("%d\n", (int)(upper_bound(num.begin(), num.end(), r) - lower_bound(num.begin(), num.end(), l)));
    }

    return 0;
}
