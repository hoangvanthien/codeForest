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

#define FOR(i, x, y) for(int i = (x); i<=(y); ++i)
#define REP(i, r) for(int i = 0; i < (r); ++i)
#define DFOR(i, x, y) for(int i = (x); i>=(y); --i)
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
#define ld long double
#define maximize(x, y) x=max(x,(y))
#define minimize(x, y) x=min(x,(y))
#define nl puts("")
#define sca(a, n) FOR(i,1,n) scanf("%d", &a[i])
#define sci(i) scanf("%d",&i)

const int N = 100002;
const int oo = 1000000007;
int n, m, a[N], b[N];
multiset<int> ar;
vector<int> ans;

bool process(int k) {
    int i = 1;
    int dist = *ar.begin() - b[1];
    forit(it, ar) {
        if (b[i] + dist != *it) return false;
        ++i;
    }
    ans.pb(k);
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    sci(n);
    sca(a, n);
    sci(m);
    sca(b, m);
    sort(b + 1, b + 1 + m);
    if (n < m) {
        cout << 0;
        return 0;
    }
    FOR(i, 1, m) ar.insert(a[i]);
    process(1);
    FOR(i, m + 1, n) {
        ar.erase(ar.find(a[i - m]));
        ar.insert(a[i]);
        process(i - m + 1);
    }
    printf("%d\n", (int)ans.size());
    forit(it, ans) printf("%d\n", *it);
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}