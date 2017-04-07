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
#ifdef ONLINE_JUDGE
#define printLL(x) printf("%I64d", x)
#else
#define printLL(x) cout << x
#endif

const int N = 200005;
const int oo = 1000000007;
int n, a[N];
II f[N];
vector<int> ans;
bool mark[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("wagons.inp", "r", stdin);
   freopen("wagons.out", "w", stdout);
#endif // ONLINE_JUDGE
    sci(n);
    sca(a, n);
    ++n;
    a[n] = oo;
    f[n] = mp(a[n], n);
    DFOR(i, n - 1, 1) {
        II p = f[i + 1];
        if (p.F >= a[i]) f[i] = mp(a[i], i);
        else f[i] = f[i + 1];
    }

    stack<int> stk;
    for (int i = 1; i <= n;) {
        while (stk.size()) {
            int t = stk.top();
            if (t <= f[i].F) {
                stk.pop();
                ans.pb(t);
            } else break;
        }
        int ind = f[i].S;
        while (i <= ind) {
            stk.push(a[i]);
            ++i;
        }
    }

    forit(it, ans) printf("%d ", *it);

//    int Min = *min_element(a + 1, a + 1 + n);
//    FOR(i, 1, n) if (a[i] == Min) {
//            for (; i < n; ++i) {
//                mark[i] = true;
//                i = f[i + 1].S - 1;
//            }
//            break;
//        }
//
//    FOR(i, 1, n) if (mark[i]) printf("%d ", a[i]);
//    DFOR(i, n, 1) if (!mark[i]) printf("%d ", a[i]);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}