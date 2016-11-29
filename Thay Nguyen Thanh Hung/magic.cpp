#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define DFOR(i, x, y) for(int i = (x); i>=(y); --i)
#define db(x) cerr << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define II pair<int,int>
#define LL long long
#define ld long double
#define maximize(x, y) x=max(x,(y))
#define minimize(x, y) x=min(x,(y))
#define nl puts("")
#define sca(a, n) FOR(i,1,n) scanf("%d", &a[i])
#define sci(i) scanf("%d",&i)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sciiii(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define scni(i) int i; scanf("%d",&i)
#define scnii(a, b) int a,b; scanf("%d%d", &a, &b)
#define scniii(a, b, c) int a,b,c; scanf("%d%d%d", &a, &b, &c)
#define scniiii(a, b, c, d) int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d)
#define lc node*2
#define rc node*2+1
#define vi vector<int>

const int N = 200005;
const int oo = 1000000007;
int aa[] = {7, 6, 5, 4, 3, 2, 1, 0};
int bb[] = {3, 0, 1, 2, 5, 6, 7, 4};
int cc[] = {0, 6, 1, 3, 4, 2, 5, 7};
vi v;
map<vi, int> mark;

vi a(vi &x) {
    vi res;
    DFOR(i, 7, 0) res.pb(x[i]);
    return res;
}

vi b(vi &x) {
    vi res;
    f0(i, 8) res.pb(x[bb[i]]);
    return res;
}

vi c(vi &x) {
    vi res;
    f0(i, 8) res.pb(x[cc[i]]);
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("magic.inp", "r", stdin);
    freopen("magic.out", "w", stdout);
#endif // ONLINE_JUDGE
    v.resize(8);
    f0(i, 8) sci(v[i]);
    vi start;
    f1(i, 8) start.pb(i);
    queue<vi > q;
    q.push(start);
    while (q.size()) {
        vector<int> u = q.front();
        q.pop();
        if (u == v) break;
        int du = mark[u];
        vi temp = a(u);
        if (!mark[temp]) {
            mark[temp] = du + 1;
            q.push(temp);
        }
        temp = b(u);
        if (!mark[temp]) {
            mark[temp] = du + 1;
            q.push(temp);
        }
        temp = c(u);
        if (!mark[temp]) {
            mark[temp] = du + 1;
            q.push(temp);
        }
    }
    cout << mark[v];
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}