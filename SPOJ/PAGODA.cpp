#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define FORc(i,x,y) for(char i = (x); i<=(y); ++i)
#define DFORc(i,x,y) for(char i = (x); i>=(y); --i)
#define db(x) cout<<#x<<" = "<<x<<endl;
#define maxN 200002
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo 1e9+7
#define II pair<int,int>
#define LL long long

//typedef string bigint;

// basic function
string strrev(string _a)
{
    reverse(_a.begin(), _a.end());
    return _a;
}
// end basic function

map<char, int> cnt, _cnt;
int n;
string A,B,s1,s2,ans;
bool gter;
char tmp[maxN];

void readStr(string &s) {
    char tmp[maxN];
    scanf("%s", tmp);
    s.assign(tmp);
}

void init()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ans = "";
    string C;
    //std::ios::sync_with_stdio(false);
    scanf("%d", &n);
    scanf("%s", tmp);
    A.assign(tmp);
    scanf("%s", tmp);
    B.assign(tmp);
    scanf("%s", tmp);
    C.assign(tmp);
    FORc(c,'0','9') cnt[c] = 0;
    FOR(i,1,n)
    {
        cnt[C[i-1]]++;
    }
//    C = "";
//    FOR(i,1,A.length()) C+="*";
    if (A>B) s1 = A; else s1 = B;
    //db(s1);
    if (strrev(A) < strrev(B)) s2 = A; else s2 = B;
    //db(s2);
}

inline bool attemp(int pos, char c)
{
    FORc(c1, '0', '9') _cnt[c1] = cnt[c1];
    _cnt[c] --;
    //forit(it,_cnt) printf("_cnt[%c] = %d\n", it->F, it->S);
    bool _gter = gter;
    if (c > s1[pos]) _gter = true;
    FOR(i,pos+1,n-1)
    {
        if (_gter) break;
        // try to put greater digit
        //if (s1[i] != '9')
        {
            char temp = s1[i]+1;
            DFORc(c1, '9', temp)
            if (_cnt[c1] > 0)
            {
                _gter = true;
                break;
            }
        }
        if (_gter) break;
        // if we can't put greater digit? try to put equally digit
        if (_cnt[s1[i]] == 0) return false;
        _cnt[s1[i]] --;
    }
    if (!_gter) return false;

    FORc(c1, '0', '9') _cnt[c1] = cnt[c1];
    _cnt[c] --;
    bool sler = false;
    //if (c < s2[pos] && pos == n-1) sler = true;
    DFOR(i,n-1,pos+1)
    {
        //if (sler) break;
        // try to put a smaller digit
        //if (s2[i] != '0')
        {
            char temp = s2[i]-1;
            DFORc(c1, temp, '0')
            if (_cnt[c1] > 0)
            {
                sler = true;
                break;
            }
        }
        if (sler) break;
        // if we can't put a smaller digit? try another equally one!
        if (_cnt[s2[i]] == 0) return false;
        _cnt[s2[i]]--;
    }
    if (_gter && sler) return true;
    // in case we can put all remain digits as equal as corresponding digits in s2,
    // we have to check if all the string C is smaller than s2
    ans = ans + c;
    DFOR(i, pos, 0)
    if (ans[i] < s2[i]) {ans.erase(pos,1); return true;}
    else
        if (ans[i] > s2[i]) {ans.erase(pos-1,1); return false;}
    // final case, the whole string C is equal to s2, so the result have to false
    ans.erase(pos,1);
    return false;
}

int main()
{
    init();
//    db(A);
//    db(B);
//    db(C);
    gter = false;
    FOR(i,0,n-1)
    {
        bool exist = false;
        char startpoint;
        startpoint = gter ? '0' : s1[i];
        FORc(ch, startpoint, '9')
        if (cnt[ch] > 0)
            if (attemp(i, ch))
            {
                // C[i] = c;
                ans = ans + ch;
                if (ch>s1[i]) gter = true;
                //db(C);
                --cnt[ch];
                exist = true;
                break;
            }
        if (!exist)
        {
            cout<<"-1";
            exit(0);
        }
    }

//    strcpy(tmp, ans.c_str());
//    printf("%s", tmp);
    cout<<ans<<endl;

}


