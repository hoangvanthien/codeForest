#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 100002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

string s;
vector<char> vc;
vector<int> num, w;

void init() {
    freopen("marbles.inp", "r", stdin);
    freopen("marbles.out", "w", stdout);
    getline(cin, s); s = s+s;
}

int main() {
	init();
	int lastr, lastb;
	vc.pb('@');
	num.pb(0);
	w.pb(0);
	FOR(i,0,s.length()-2)
	if (s[i] != 'w')
		if (!vc.empty() && s[i] == vc.back()) num[num.size()-1]++; else {
			vc.pb(s[i]);
			num.pb(1);
			w.pb(0);
		}
	else
        if (w[w.size()-1] < s.length()/2) w[w.size()-1]++;
	w.pb(0); num.pb(0);
	int ans = 0;
	FOR(i,0,vc.size()-1)
	if (i>0) ans = max(ans, num[i]+num[i+1]+w[i-1]+w[i]+w[i+1]);
	else ans = max(ans, num[i]+num[i+1]+w[i]+w[i+1]);
	printf("%d", ans);
}
