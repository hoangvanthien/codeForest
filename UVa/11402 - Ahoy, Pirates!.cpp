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

const int N = 1024005;
const int oo = 1000000007;

struct vertex {
    int sum, lazy;
};

vertex T[N * 4];
char temp[N];
int cntAns;

inline void initTree(int node, int l, int r) {
    if (l == r) {
        T[node].sum = (temp[l - 1] == '1');
        T[node].lazy = 0;
        return;
    }
    int mid = (l + r) / 2;
    initTree(node * 2, l, mid);
    initTree(node * 2 + 1, mid + 1, r);
    T[node].sum = T[node * 2].sum + T[node * 2 + 1].sum;
    T[node].lazy = 0;
}

// 1: change all to 1
// 2: change all to 0
// 3: flip all

inline void lazyUpdate(int node, int l, int r, int style) {

    if (style == 1) {
        T[node].sum = r - l + 1;
        T[node].lazy = style;
    }
    else if (style == 2) {
        T[node].sum = 0;
        T[node].lazy = style;
    }
    else if (style == 3) {
        T[node].sum = r - l + 1 - T[node].sum;
        if (T[node].lazy == 1) T[node].lazy = 2;
        else if (T[node].lazy == 2) T[node].lazy = 1;
        else if (T[node].lazy == 3) T[node].lazy = 0;
        else T[node].lazy = 3;
    }

}

inline void update(int node, int l, int r, int i, int j, int style) {
    if (j < l || i > r || l > r) return;
    int mid = (l + r) / 2;
    if (i <= l && r <= j) {
        lazyUpdate(node, l, r, style);
        return;
    }
    if (T[node].lazy) {
        int v = T[node].lazy;
        lazyUpdate(node * 2, l, mid, v);
        lazyUpdate(node * 2 + 1, mid + 1, r, v);
        T[node].lazy = 0;
    }
    update(node * 2, l, mid, i, j, style);
    update(node * 2 + 1, mid + 1, r, i, j, style);
    T[node].sum = T[node * 2].sum + T[node * 2 + 1].sum;
}

inline int getSum(int node, int l, int r, int i, int j) {
    if (j < l || i > r || l > r) return 0;
    int mid = (l + r) / 2;
    if (i <= l && r <= j) return T[node].sum;
    if (T[node].lazy) {
        int v = T[node].lazy;
        lazyUpdate(node * 2, l, mid, v);
        lazyUpdate(node * 2 + 1, mid + 1, r, v);
        T[node].lazy = 0;
    }
    int res = getSum(node * 2, l, mid, i, j);
    res += getSum(node * 2 + 1, mid + 1, r, i, j);
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    int Test;
    scanf("%d", &Test);
    f1(__case, Test) {
        printf("Case %d:\n", __case);
        int cntPair, time, n = 0;
        char s[51];
        sci(cntPair);
        while (cntPair--) {
            memset(s, 0, sizeof s);
            scanf("%d\n%s", &time, s);
            while (time--) {
                REP(i, strlen(s)) temp[n++] = s[i];
            }
        }
        initTree(1, 1, n);
        int cntQuery;
        cntAns = 0;
        scanf("%d\n", &cntQuery);
        while (cntQuery--) {
            char ch;
            int x, y;
            scanf("%c %d %d\n", &ch, &x, &y);
            ++x;
            ++y;
            if (ch == 'F') update(1, 1, n, x, y, 1);
            else if (ch == 'E') update(1, 1, n, x, y, 2);
            else if (ch == 'I') update(1, 1, n, x, y, 3);
            else {
                printf("Q%d: %d\n", ++cntAns, getSum(1, 1, n, x, y));
            }
        }

    }

#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}