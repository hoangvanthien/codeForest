#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1

const int N = 1002;
const int oo = 1000000007;
map<string, int> m;
string rev[N];
int b[N];
bool p[N];
int main() {
	 freopen("duongham.inp", "r", stdin);
	 freopen("duongham.out", "w", stdout);
//	#ifndef ONLINE_JUDGE
//	freopen("input.inp", "r", stdin);
//	#endif // ONLINE_JUDGE
	int n; scanf("%d\n", &n);
	FOR(i,1,n) {
        string s; getline(cin,s);
        m[s] = i;
        rev[i] = s;
	}
	FOR(i,1,n) {
        string s; getline(cin,s);
        b[i] = m[s];
	}
	FOR(i,1,n) {
//	    bool pass = 0;
        FOR(j,1,i-1) if (b[j] > b[i]) p[b[j]] = 1;
	}
	int cnt = 0;
	FOR(j,1,n) cnt += p[j];
	printf("%d\n",cnt);
	FOR(j,1,n) if (p[b[j]]) cout << rev[b[j]] << endl;
}

