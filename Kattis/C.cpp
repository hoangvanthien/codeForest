#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 1002
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

map<char, int> m;
string s;
bool selected[maxN];
int n;
int ar[maxN][maxN];

void init() {
//    #ifndef ONLINE_JUDGE
//        freopen("input.inp", "r", stdin);
//    #endif // ONLINE_JUDGE
    scanf("%d", &n);
    getline(cin, s);
    getline(cin, s);
}

int main() {
	init();
	int ans = 0;
	int i = 0;
        m.clear();
        FOR(j,i,s.length()-1) {
            m[s[j]]++;
            ar[i][j] = abs(m['M'] - m['W']);
        }
//	}
    FOR(j,0,s.length()-1)
    if (ar[0][j] <= n)
        ans = max(ans, j+1);
    else if (ar[0][j] >= n+2) break;
	printf("%d", ans);
}
