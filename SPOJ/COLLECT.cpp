#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 100002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define CC pair<collection, collection>
#define LL long long

struct collection {
	int z, s, m;
	bool operator < (const collection &b) const {
		return (z < b.z && s < b.s && m < b.m);
	}
	bool operator <= (const collection &b) const {
		return (z <= b.z && s <= b.s && m <= b.m);
	}
	collection operator - (const collection &b) const {
		collection res;
		res.z = z - b.z; res.s = s - b.s; res.m = m - b.m;
		return res;
	}
	collection operator + (const collection &b) const {
		collection res;
		res.z = z + b.z; res.s = s + b.s; res.m = m + b.m;
		return res;
	}
};

collection start, fin;
CC exchange[maxN];
int ar[5][5][5];
int n, K;

inline collection mc(int z0, int s0, int m0) {
	collection res;
	res.z = z0; res.s = s0; res.m = m0;
	return res;
}

bool combine(collection _c, CC _ex) {
	if (_ex.F <= _c) {
        collection temp = _c - _ex.F + _ex.S;
		if (mc(0,0,0) <= temp && temp <= mc(4,4,4)) return true;
		else return false;
	}
	else return false;
}

bool worth(collection _c) {
    if (fin <= _c) return true;
    else return false;
}

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    int _z, _s, _m, __z, __s, __m;
    scanf("%d", &K);
    scanf("%d%d%d", &_z, &_s, &_m);
    start = mc(_z, _s, _m);
    scanf("%d%d%d", &_z, &_s, &_m);
    fin = mc(_z, _s, _m);
    n = 0;
    while (scanf("%d%d%d%d%d%d", &_z, &_s, &_m, &__z, &__s, &__m) != EOF) {
    	exchange[++n] = mp(mc(_z, _s, _m), mc(__z, __s, __m));
    }
    FOR(i,0,4) FOR(j,0,4) FOR(k,0,4) ar[i][j][k] = K+1;
}

int main()
{
	init();
    ar[start.z][start.s][start.m] = 0;
    FOR(__k,1,K)
	FOR(t,1,n) {
	    DFOR(i,4,0) DFOR(j,4,0) DFOR(k,4,0) {
	    	if (worth(mc(i,j,k))) continue;
            collection temp = mc(i,j,k);
            if (ar[i][j][k] != K+1) {
                collection temp2 = temp-exchange[t].F+exchange[t].S;
                if (combine(temp, exchange[t])) ar[temp2.z][temp2.s][temp2.m] = min(ar[temp2.z][temp2.s][temp2.m], ar[i][j][k] + 1);
            }
	    }
	}
    int cnt = 0;

    FOR(i,fin.z,4) FOR(j,fin.s,4) FOR(k,fin.m,4)
	if (fin <= mc(i,j,k) && ar[i][j][k] <= K) ++cnt;

	if (cnt == 0) {
        printf("-1");
        return 0;
    }
    printf("%d\n", cnt);
	FOR(i,fin.z,4) FOR(j,fin.s,4) FOR(k,fin.m,4)
	if (fin <= mc(i,j,k) && ar[i][j][k] <= K) {
		printf("%d %d %d %d\n", i, j, k, ar[i][j][k]);
	}
}

