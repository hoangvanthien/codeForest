/*
    github.com/hoangvanthien
    Thien Van Hoang
*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define maxN 25
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e18
#define II pair<int,int>
#define LL long long

int a,b,c,T;
LL f[maxN][maxN][maxN],Ans;

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
    #endif // ONLINE_JUDGE
}

void print()
{

}

int main()
{
	init();
	scanf("%d", &T);
	while (T--)
    {
        Ans = INT_MIN;
        scanf("%d%d%d", &a, &b, &c);
        FOR(i,1,a) FOR(j,1,b) FOR(k,1,c)
        {
            LL x;
            scanf("%lld", &x);
//            f[i][j][k] = x + f[i][j][k-1] + (f[i-1][j][k] - f[i-1][j][k-1]) + (f[i][j-1][k] - f[i][j-1][k-1] - (f[i-1][j-1][k] - f[i-1][j-1][k-1]))
            f[i][j][k] = x + f[i][j][k-1] + f[i-1][j][k] + f[i][j-1][k];
            f[i][j][k] -= f[i-1][j][k-1] + f[i][j-1][k-1] + f[i-1][j-1][k];
            f[i][j][k] += f[i-1][j-1][k-1];
        }
        FOR(i,1,a) FOR(j,1,b) FOR(k,1,c)
        {
            FOR(_i,i,a) FOR(_j,j,b) FOR(_k,k,c)
            {
                LL part;
                //part = f[_i][_j][_k] - f[_i][_j][_k-k] - (f[_i-i][_j][_k] - f[_i-1][_j][_k-1]) - (f[_i][_j-j][_k] - f[_i][_j-j][_k-k] - (f[_i-i][_j-j][_k] - f[_i-i][_j-j][_k-k]));
//                part = f[_i][_j][_k];
//                part -= f[_i-i][_j-j][_k-k];
//                part += f[_i-i][_j][_k-k] + f[_i][_j-j][_k-k] + f[_i-i][_j-j][_k];
//                part -= f[_i][_j][_k-k] + f[_i-i][_j][_k] + f[_i][_j-j][_k];
                part = f[_i][_j][_k];
                part -= f[i-1][j-1][k-1];
                part += f[i-1][_j][k-1] + f[_i][j-1][k-1] + f[i-1][j-1][_k];
                part -= f[_i][_j][k-1] + f[i-1][_j][_k] + f[_i][j-1][_k];

                Ans = max(Ans, part);
            }
        }
        //printf("%lld\n\n", Ans);
        cout<<Ans<<endl;
        if (T) cout<<endl;
    }
}
