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

typedef char* pchar;
const int N = 100002;
const int oo = 1000000007;

int val(char ch) {return ch - '0';}
char chr(int val) {return '0' + val;}

char chradd(char a, char b, int &carry) {
    int temp = val(a) + val(b) + carry;
    carry = temp/10;
    return chr(temp %10);
}
pchar stradd (char a[], char b[], char c[]) {
    int i = 0, carry = 0;
    while (a[i] && b[i]) c[i++] = chradd(a[i], b[i], carry);
    if (a[i]) while (a[i]) c[i++] = chradd(a[i], '0', carry);
    else while (b[i]) c[i++] = chradd(b[i], '0', carry);
    if (carry) c[i++] = chr(carry);
    c[i] = 0;
    return c;
}

char chrmul(char a, char b, int &carry) {
    int temp = val(a) * val(b) + carry;
    carry = temp/10;
    return chr(temp %10);
}
pchar strmul(char a[], char b[], char c[]) {
    int jb = 0;
    pchar temp = new char[strlen(a)+2];
    do {
        int ja = 0, carry = 0;
        do {
            temp[ja++] = chrmul(a[ja], b[jb], carry);
        } while (a[ja]);
        if (carry) temp[ja++] = chr(carry);
        temp[ja]=0;
        if (jb == 0) strcpy(c, temp);
        else stradd(c+jb, temp, c+jb);
        jb++;
    } while (b[jb]);
    return c;
}
void strrev(char a[]) {
    int n = strlen(a);
    FOR(i,0,n/2-1) swap(a[i], a[n-i-1]);
}
char A[N], B[N], C[N];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	scanf("%s\n%s", A, B);
    strrev(A);
    strrev(B);
	strmul(A, B, C);
	strrev(C);
	cout << C;
    return 0;
}

