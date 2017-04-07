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

const int N = 30005;
const int oo = 1000000007;
int n, a[N];

struct Node {
    int cnt;
    Node *left, *right;

    inline Node(int c, Node *l, Node *r) { cnt = c, left = l, right = r; }
};

Node *T[N];
Node *null_tree;
set<int> s;
int Hash[N];

inline Node *insert(Node *node, int l, int r, int v) {
    if (l > r) return null_tree;
    if (v < Hash[l] || v > Hash[r]) return node;
    if (l == r) {
        return new Node(node->cnt + 1, 0, 0);
    }
    int mid = (l + r) / 2;
    return new Node(node->cnt + 1, insert(node->left, l, mid, v), insert(node->right, mid + 1, r, v));
}

inline int query(Node *node, int l, int r, int k) {
    if (l > r) return 0;
    if (Hash[r] <= k) return 0;
    if (k < Hash[l]) return node->cnt;
    int mid = (l + r) / 2;
    return query(node->left, l, mid, k) + query(node->right, mid + 1, r, k);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // ONLINE_JUDGE
    int cq;
    sci(n);
    sca(a, n);
    sci(cq);
    f1(i, n) s.insert(a[i]);
    int imax = 0;
    forit(it, s) Hash[++imax] = *it;
    null_tree = new Node(0, 0, 0);
    null_tree->left = null_tree->right = null_tree;
    T[0] = null_tree;
    f1(i, n) T[i] = insert(T[i - 1], 1, imax, a[i]);
    int la = 0;
    while (cq--) {
        scniii(i, j, k);
        i ^= la, j ^= la, k ^= la;
        maximize(i,1);
        minimize(j,n);
        if (i <= j)
            la = query(T[j], 1, imax, k) - query(T[i - 1], 1, imax, k);
        else la = 0;
        printf("%d\n", la);
    }
    return 0;
#ifndef ONLINE_JUDGE
    cout << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}