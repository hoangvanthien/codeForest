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

string s[maxN];
int num[maxN][3];

void init() {
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
}

int main() {
	init();
	int T, n, m;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		getline(cin, s[1]);
		FOR(i,1,n) getline(cin, s[i]);
		m = s[1].length();
		FOR(i,1,n) num[i][1] = num[i][2] = 0;
		FOR(i,1,n) FOR(j,0,m-1) {
			if (s[i][j] == 'a') num[i][1]++; else num[i][2]++;
		}
		int min1 = oo, min2 = oo;
		FOR(i,1,n) min1 = min(min1, num[i][1]), min2 = min(min2, num[i][2]);
		printf("%d\n", min(min1, min2));
	}
}
