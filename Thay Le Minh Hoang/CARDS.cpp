#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
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

struct Swap {int i,m,j;};

Swap ar[maxN];
int n,k,x;

int Undo(Swap ss, int pos) {
//	if (pos < ss.i) {
//		if (ss.j <= pos) return pos + ss.m;
//		else return pos;
//	} else if (pos > ss.i+ss.m-1) {
//		pos -= ss.m;
//		if (ss.j > pos) return pos;
//		else return pos + ss.m;
//	} else {
//		return pos - ss.i + ss.j;
//	}
	if (pos < ss.j) {
		if (ss.i <= pos) return pos + ss.m;
		else return pos;
	} else if (pos > ss.j+ss.m-1) {
		pos -= ss.m;
		if (ss.i > pos) return pos;
		else return pos + ss.m;
	} else {
		return pos - ss.j + ss.i;
	}
}

void init() {
    freopen("cards.inp", "r", stdin);
    freopen("cards.out", "w", stdout);
    scanf("%d%d%d", &n, &k, &x);
    //k = n;
    FOR(i,1,x) scanf("%d%d%d", &ar[i].i, &ar[i].m, &ar[i].j);
}

int main() {
	init();
	FOR(i,1,k) {
		int temp = i;
		DFOR(j,x,1)
            temp = Undo(ar[j], temp);
		printf("%d ", temp);
	}
}

