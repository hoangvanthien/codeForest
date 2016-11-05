#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define REP(i,r) for(int i = 0; i < (r); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
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
#define maximize(x,y) x=max(x,(y))
#define minimize(x,y) x=min(x,(y))


const int N = 100002;
const int oo = 1000000007;

int c[N], RA[N], SA[N], tempSA[N], tempRA[N];
int n;
string s;

void countingSort(int k) {
    memset(c, 0, sizeof c);
    int imax = max(n, 300), sum = 0;
    REP(i,n) if (i+k < n) c[RA[i+k]]++; else c[0]++;
    REP(i,imax) {
        int temp = c[i];
        c[i] = sum;
        sum += temp;
    }
    REP(i,n) if (SA[i]+k < n) tempSA[c[RA[SA[i]+k]]++] = SA[i]; else tempSA[c[0]++] = SA[i];
    REP(i,n) SA[i] = tempSA[i];
}

void constructSA() {
    int r;
    REP(i,n) RA[i] = s[i];
    REP(i,n) SA[i] = i;
    for(int k = 1; k < n; k*=2) {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        FOR(i,1,n-1) tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        REP(i,n) RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;
    }
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	getline(cin, s);
	s += '$';
	n = s.size();
	constructSA();
    FOR(i,1,n-1) printf("%d\n", SA[i]);
}

