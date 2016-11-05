#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 1000002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

int n;
string s;
II a[maxN];
int cnt[maxN], ord[maxN];
map<char, vector<int> > m;

void init() {
//    #ifndef ONLINE_JUDGE
//        freopen("input.inp", "r", stdin);
//    #endif // ONLINE_JUDGE
    getline(cin, s);
    n = s.length();
    int q = 1;
    FOR(i,0,s.length()-1) a[i+1].F = s[i] - '0' , a[i+1].S = i+1, ++cnt[a[i+1].F], ord[i+1] = i+1;
    //sort(a+1, a+1+s.length());
}

int main() {
	init();
	int ans = 0;
	int i = 1, j = 1;
	FOR(k, 0, 2) {
	    FOR(i,1,n) ord[i] =
	}
	printf("%d", ans);
}

