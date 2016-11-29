// RM
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

const int N = 200005;
const int oo = 1000000007;
int n, k, a[N];
vector<pair<LL, LL> > v;

//bool cmp(const pair<LL, LL> &x, const pair<LL, LL> &y) {
//    return mp(x.S, -x.F) <
//}

void process(int x) {
    if (x == 0) {
        v.pb(mp(1LL, 0LL));
        return;
    }
    LL ex = 1;
    while (x) {
        v.pb(mp(ex, -ex * (x % 10)));
        ex *= 10;
        x /= 10;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("digits.inp", "r", stdin);
   freopen("digits.out", "w", stdout);
#endif // ONLINE_JUDGE
    scii(n, k);
    LL sum1 = 0;
    sca(a, n);
    f1(i, n) sum1 += a[i];
    f1(i, n) process(a[i]);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    forit(it, v) it->S *= -1;
    for (int i = 0; i < v.size() && k; ++i) {
        if (v[i].S != v[i].F * 9) {
            v[i].S = v[i].F * 9;
            --k;
        }
    }
//    f0(i, min(int(v.size()), k)) v[i].F = v[i].S * 9;
    LL sum2 = 0;
    f0(i, (int) v.size()) sum2 += v[i].S;
    cout << sum2 - sum1;
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}