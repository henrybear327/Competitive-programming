#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int, int> ver, hor;
    set< pair<int, int> > s;
    bool ok = true;
    for(int i = 0; i < 8; i++) {
	int x, y;
	scanf("%d %d", &x, &y);

	ver[x]++;
	hor[y]++;
	if( s.find( make_pair(x, y) ) != s.end())
	    ok = false;
	s.insert( make_pair(x, y) );
    }
    
    if(ver.size() != hor.size() || ver.size() != 3 || hor.size() != 3)
	ok = false;
    int check[3] = {3, 2, 3};
	
    int idx = 0;
    for(auto i = ver.begin(); i != ver.end(); i++)
	if(i->second != check[idx++])
	    ok = false;
    idx = 0;
    for(auto i = hor.begin(); i != hor.end(); i++)
	if(i->second != check[idx++])
	    ok = false;
    

    if(ok)
	printf("respectable\n");
    else
	printf("ugly\n");
    return 0;
}
