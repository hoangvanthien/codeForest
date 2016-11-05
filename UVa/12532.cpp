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

const int N = 400002;
const int oo = 1000000007;

int a[N];
II T[N];
char ans[N];

void initTree(int node, int l, int r) {
    if (r < l) return;
    if (l == r) {
        T[node] = mp(a[l] < 0, a[l] == 0);
        return;
    }
    int mid = (l+r)/2;
    initTree(node*2, l, mid);
    initTree(node*2+1, mid+1, r);
    T[node].F = T[node*2].F + T[node*2+1].F;
    T[node].S = T[node*2].S + T[node*2+1].S;
}

void update(int node, int l, int r, int k, int val) {
    if (r < l) return;
    if (k < l || k > r) return;
    if (l == r && l == k) {
        T[node] = mp(val < 0, val == 0);
        return;
    }
    int mid = (l+r)/2;
    update(node*2, l, mid, k, val);
    update(node*2+1, mid+1, r, k, val);
    T[node].F = T[node*2].F + T[node*2+1].F;
    T[node].S = T[node*2].S + T[node*2+1].S;
}

II getSum(int node, int l, int r, int i, int j) {
    if (r < l) return mp(0,0);
    if (j < l || i > r) return mp(0,0);
    if (i <= l && r <= j) return T[node];
    int mid = (l+r)/2;
    II temp1 = getSum(node*2, l, mid, i, j);
    II temp2 = getSum(node*2+1, mid+1, r, i, j);
    return mp(temp1.F + temp2.F, temp1.S + temp2.S);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    int n,q;
    while (scanf("%d%d", &n, &q) != EOF) {
        memset(a, 0, sizeof a);
        memset(T, 0, sizeof T);
        memset(ans, 0, sizeof ans);
        f1(i,n) sci(a[i]);
        initTree(1,1,n);
        scanf("\n");
        while(q--) {
            char s;
            int x,y;
            scanf("%c %d %d\n", &s, &x, &y);
            if (s == 'C') {
                update(1,1,n,x,y);
            } else {
                II res = getSum(1,1,n,x,y);
                if (res.S > 0) ans[strlen(ans)] = '0';
                else {
                    if (res.F % 2 == 0) ans[strlen(ans)] = '+';
                    else ans[strlen(ans)] = '-';
                }
            }
        }
        printf("%s\n", ans);
    }
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
