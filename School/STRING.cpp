#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 202
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound

string s, ans;
int g;
map<char, int> m, cnt;
pair<char, int> a[maxN];

int gcd(int x, int y) {
	while (y != 0) {
		int r = x%y;
		x = y;
		y = r;
	}
	return x;
}

int main() {
//	freopen("string.inp", "r", stdin);
//	freopen("string.out", "w", stdout);
	 #ifndef ONLINE_JUDGE
	 freopen("input.inp", "r", stdin);
	 #endif // ONLINE_JUDGE
	getline(cin, s);
	int n = s.length();
	FOR(i,0,s.length()-1) a[i+1] = mp(s[i], ++m[s[i]]);
	forit(it, m) if (g == 0) g = it->S; else g = gcd(g, it->S);
//	db(g);
	FOR(i,1,n)
	if (cnt[s[i-1]] < m[s[i-1]]) {
		cout<<s[i-1];
		cnt[s[i-1]] += g;
	}
}
