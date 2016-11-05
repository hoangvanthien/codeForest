/*
You can go the distance
You can run the mile
You can walk straight through hell with a smile

You can be the hero
You can get the gold
Breaking all the records they thought never could be broke

Yeah, do it for your people
Do it for your pride
How are you ever gonna know if you never even try?

Do it for your country
Do it for your name
'Cause there's gonna be a day...

When you're standing in the hall of fame
And the world's gonna know your name
'Cause you burn with the brightest flame

 -- "Hall Of Fame" --

 */

// Code by an idiot.

#include "bits/stdc++.h"

using namespace std;

#define f1(i, r) for(int i=1; i<=(r); ++i)
#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define REP(i, r) for(int i = 0; i < (r); ++i)
#define f0(i, r) for(int i = 0; i < (r); ++i)
#define DFOR(i, x, y) for(int i = (x); i>=(y); --i)
#define db(x) cerr << #x << " = " << x << endl;
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
#define ld long double
#define maximize(x, y) x=max(x,(y))
#define minimize(x, y) x=min(x,(y))
#define nl puts("")
#define sca(a, n) FOR(i,1,n) scanf("%d", &a[i])
#define sci(i) scanf("%d",&i)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sciiii(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define lc node*2
#define rc node*2+1

const int N = 35;
const int oo = 1000000007;
int n, a[N];
map<LL, int> m;
map<LL, int>::iterator iter;
LL f[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE

    sci(n);
    f0(i, n) {
        sci(a[i]);
        f[i] = (i - 1 >= 0 ? f[i - 1] : 0) + a[i];
    }
    int t = n / 2;
    LL sum = 0;
    f0(i, 1 << t) {
        sum = 0;
        f0(j, t) if (i & (1 << j)) {
                sum += a[j];
            }
        m[sum * 2 - f[t - 1]]++;
    }
    t = n - n / 2;
    pair<LL, LL> p1, p2;
    LL ans, minDif = (LL) oo * oo, temp = 0;
    f0(i, 1 << t) {
        sum = 0;
        f0(j, t) if (i & (1 << j)) {
                sum += a[j + t - (n % 2)];
            }
        LL dif = sum * 2 - (f[n - 1] - f[n / 2 - 1]);

        iter = m.lower_bound(-dif);
        temp = iter->F;
        if (iter != m.end()) {
            p1.F = abs(iter->F + dif);
            p1.S = iter->S;
            if (minDif > p1.F) {
                minDif = p1.F;
                ans = p1.S;
            } else if (minDif == p1.F) ans += p1.S;
        }

        if (iter != m.begin()) {
            --iter;
            temp = iter->F;
            p2.F = abs(iter->F + dif);
            p2.S = iter->S;
            if (minDif > p2.F) {
                minDif = p2.F;
                ans = p2.S;
            } else if (minDif == p2.F) ans += p2.S;
        }

    }
    printf("%lld %lld", minDif, ans / 2);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}