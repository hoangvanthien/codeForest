#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, SS) for(__typeof(SS.begin()) it = SS.begin(); it!=SS.end(); ++it)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 100002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

map<string, int> m;
map<string, double> ans;
vector<string> tree;

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
    cout<< std::fixed << std::setprecision(4);

}

void print()
{

}

int main()
{
	init();
	int T,n;
	string S;
	cin >> T;
	getline(cin,S);getline(cin,S);
	while (T--)
    {
        n = 0;
        m.clear();
        while (getline(cin,S) && S.length()!=0)
        {
            m[S] ++;
            ++n;
        }
        forit(it, m)
        {
            cout << it->F << " " << (double)(it->S)*100.0/(double)(n) << endl;
        }
        if (T) cout<<endl;
    }
}
