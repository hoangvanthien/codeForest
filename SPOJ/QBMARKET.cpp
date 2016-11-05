#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define maxN 502
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

//map<II, int> f;
int s,n,c[maxN],m[maxN];
string f[501][100005];
///////
void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d%d", &s, &n);
    exit(0);
    FOR(i,1,n) scanf("%d%d", &c[i], &m[i]);
    // FOR(i,1,n) FOR(j,0,s) f[mp(i,j)] = -1;
//    FOR(j,0,s)
//    {
//    	f[mp(0,j)] = 1;
//    }
    FOR(i,0,n) f[i][0] = "1";
    FOR(i,1,n) FOR(j,1,s) f[i][j] ="0";
//    FOR(i,1,n) sum[i] = sum[i-1]+c[i]*m[i];
}

//char chr(int i) {return i+'0';}
//int val(char ch) {return ch-'0';}
//
//string strrev(string a)
//{
//    reverse(a.begin(), a.end());
//    return a;
//}
//
//char addChar(char a, char b, int &carry)
//{
//    int temp = val(a) + val(b) + carry;
//    carry = temp/10;
//    return chr(temp%10);
//}
//

//string Add(string a, string b)
//{
//    string res = "";
//    a = strrev(a); b = strrev(b);
//    int i = 0, carry = 0;
//    while (i < min(a.length(), b.length()))
//    {
//        res+=addChar(a[i], b[i], carry);
//        ++i;
//    }
//    if (a[i])
//        while (a[i]) res+=addChar(a[i++], '0', carry);
//    else
//        while (b[i]) res+=addChar(b[i++], '0', carry);
//    return strrev(res);
//}
//
//void optimize()
//{
//	FOR(i,1,n)
//	{
//		FOR(j,1,s)
//		{
////		    db(f[mp(i,j)]);
////            if (m[i]*c[i] < j) break;
////            if (sum[i] < j) break;
//			for (int k = 0; k <= m[i] && k*c[i] <= j; ++k) f[i][j] = Add(f[i][j], f[i-1][j-k*c[i]]);
////			printf("%d %d %d\n", i, j, f[mp(i,j)]);
//		}
//	}
//}

int main()
{
	init();
//	optimize();
	cout<<f[n][s];
}

