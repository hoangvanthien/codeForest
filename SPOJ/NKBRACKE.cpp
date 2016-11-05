#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 100002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound

struct NODE {
	int leng, open, close;
};
NODE T[4*maxN];
string s;
bool tt[maxN];

inline void initTree(int node, int l, int r) {
	if (r == l) {
		if (s[l-1] == '(') T[node].open = 1, T[node].close = 0; else T[node].open = 0, T[node].close = 1;
		return;
	}
	int mid = (l + r) / 2;
	initTree(node*2, l, mid);
	initTree(node*2+1, mid+1, r);
	int tmp = min(T[node*2].open, T[node*2+1].close);
	T[node].leng = T[node*2].leng + T[node*2+1].leng + tmp*2;
	T[node].open = T[node*2].open + T[node*2+1].open - tmp;
	T[node].close = T[node*2].close + T[node*2+1].close - tmp;
}

inline NODE getLength(int node, int l, int r, int i, int j) {
	if (i > r || j < l) return T[0];
	if (i <= l && r <= j) return T[node];
	int mid = (l + r) >> 1;
	NODE a = getLength(node*2, l, mid, i, j), b = getLength(node*2+1, mid + 1, r, i, j);
	int tmp = min(a.open, b.close);
	NODE res;
	res.leng = a.leng + b.leng + tmp*2; res.open = a.open + b.open - tmp; res.close = a.close + b.close - tmp;
	return res;
}

inline void update(int node, int l, int r, int index, char val) {
	if (index < l || index > r) return;
	if (l == r) {
		s[l-1] = val;
		if (s[l-1] == '(') T[node].open = 1, T[node].close = 0; else T[node].open = 0, T[node].close = 1;
		return;
	}
	int mid = (l + r) / 2;
	update(node*2, l, mid, index, val);
	update(node*2+1, mid+1, r, index, val);
	int tmp = min(T[node*2].open, T[node*2+1].close);
	T[node].leng = T[node*2].leng + T[node*2+1].leng + tmp*2;
	T[node].open = T[node*2].open + T[node*2+1].open - tmp;
	T[node].close = T[node*2].close + T[node*2+1].close - tmp;
}

int main() {
	// freopen(".inp", "r", stdin);
	// freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
	#endif // ONLINE_JUDGE
	ios::sync_with_stdio(0);
	int n, m, type, u, v, index; char ch;
	cin >> n >> m;
	getline(cin, s); getline(cin, s);

	initTree(1,1,n);
	NODE _node;
	FOR(i,1,m) {
		cin >> type;
//		type = 1;
		if (type == 0) {
			cin >> index >> ch;
			if (ch != s[index-1])
                update(1,1,n,index,ch);
		} else {
			cin >> u >> v;
			if ((v - u + 1) % 2) {cout << 0; continue;}
			if (v == u) {cout << 1; continue;}
			if (s[u-1] != '(') {cout << 0; continue;}
			_node = getLength(1,1,n,u,v);
			if (_node.leng == v-u+1) cout << 1; else cout << 0;
		}
	}
}
