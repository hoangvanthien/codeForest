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

string s1, s2;
map<char, int> m1, m2;

void init() {
//    #ifndef ONLINE_JUDGE
//        freopen("input.inp", "r", stdin);
//    #endif // ONLINE_JUDGE
    freopen("ad.inp", "r", stdin);
    freopen("ad.out", "w", stdout);
    getline(cin, s1);
    getline(cin, s2);
}

int main() {
	init();
	FOR(i,0,s1.length()-1) m1[s1[i]]++;
	FOR(i,0,s2.length()-1) m2[s2[i]]++;
	int ans = 0;
	for(char c = 'a'; c <= 'z'; ++c) {
		ans += abs(m1[c] - m2[c]);
	}
	printf("%d", ans);
}

