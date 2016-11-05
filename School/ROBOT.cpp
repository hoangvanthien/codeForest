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
#define III pair<int, II>
const int N = 102;
const int oo = 1000000007;
int a[N][N], d[N][N];
int main() {
	 freopen("robot.inp", "r", stdin);
	 freopen("robot.out", "w", stdout);
//	#ifndef ONLINE_JUDGE
//	freopen("input.inp", "r", stdin);
//	#endif // ONLINE_JUDGE
	int m,n; II st, fin;
	cin >> m >> n;
	FOR(i,1,m) FOR(j,1,n) cin >> a[i][j], d[i][j] = oo;
	cin >> st.F >> st.S;
	cin >> fin.F >> fin.S;
	d[st.F][st.S] = a[st.F][st.S];
    set<III> s;
    s.clear();
    s.insert(mp(a[st.F][st.S], st));
    while (!s.empty()) {
        III top = *(s.begin());
        s.erase(top);
        II u = top.S;
        FOR(i,-1,1) FOR(j,-1,1) if (abs(i)+abs(j)==1) {
            II v = mp(u.F+i, u.S+j);
            if (d[v.F][v.S] > d[u.F][u.S] + a[v.F][v.S]) {
                s.erase(mp(d[v.F][v.S], v));
                d[v.F][v.S] = d[u.F][u.S] + a[v.F][v.S];
                s.insert(mp(d[v.F][v.S], v));
            }
        }
    }
    printf("%d", d[fin.F][fin.S]);
}

