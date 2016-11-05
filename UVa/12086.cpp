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

const int N = 800002;
const int oo = 1000000007;

int T[N], a[N];

void initTree(int node, int l, int r) {
    if (r < l) return;
    if (l == r) {
        T[node] = a[l];
        return;
    }
    int mid = (l+r)/2;
    initTree(node*2, l, mid);
    initTree(node*2+1, mid+1, r);
    T[node] = T[node*2] + T[node*2+1];
}

void update(int node, int l, int r, int k, int val) {
    if (r < l) return;
    if (k < l || k > r) return;
    if (l == r && l == k) {
        T[node] = val;
        return;
    }
    int mid = (l+r)/2;
    update(node*2, l, mid, k, val);
    update(node*2+1, mid+1, r, k, val);
    T[node] = T[node*2] + T[node*2+1];
}

int getSum(int node, int l, int r, int i, int j) {
    if (r < l) return 0;
    if (j < l || i > r) return 0;
    if (i <= l && r <= j) return T[node];
    int mid = (l+r)/2;
    int res = getSum(node*2, l, mid, i, j);
    res += getSum(node*2+1, mid+1, r, i, j);
    return res;
}

bool scan(int &type, int &x, int &y) {
    char ch;
    scanf("%c", &ch);
    if (ch == 'E') {
        scanf("\n");
        return false;
    }
    scanf("%d%d", &x, &y);
    type = (ch == 'S');
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE

    int _case = 0, n = 0;
    while (scanf("%d", &n) && n) {
        if (_case) nl;
        printf("Case %d:\n", ++_case);
        memset(T, 0, sizeof T);
        memset(a, 0, sizeof a);
        f1(i,n) scanf("%d", &a[i]);
        initTree(1,1,n);
        int type, x, y;
        while (scan(type, x, y)) {
            if (type) {
                int ans = getSum(1,1,n,x,y);
                printf("%d\n", ans);
            } else {
                update(1,1,n,x,y);
            }
        }
    }

#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
