#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i <= (y); ++i)
#define DFOR(i,x,y) for(int i = (x); i >= (y); --i)
#define db(x) cout << #x << " = " << x << endl
#define mp make_pair
#define pb push_back
#define pf push_front
#define II pair<int, int>
#define F first
#define S second
#define vi vector<int>
#define new0(a) memset(a, 0, sizeof a)
#define LAST(x) (int)x.size() - 1
#define oo 1e9+7
#define LL long long
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it != var.rend(); ++it)
#define show(x) forit(it, x) cout << *it << " ";

const int N = 2002;
map<LL, int> index;
//LL rev[N*10];
vector<LL> v;  vector<char> op;
vector<LL> v2; vector<char> op2;
vector<int> dsk[N];
//LL f[N][5*N];
map<int, string> ans[N];
int visited[N], t;
int ass[N];
int n;

LL cal(int left, int right) {
    v2.clear(); op2.clear();
    v2.assign(v.begin(), v.end()); op2.assign(op.begin(), op.end());
//    LL temp = 0;
//    char last = '*';
    FOR(i,left,right-1) if (op2[i] == '*') {
        v2[i] = v2[i] * v2[i+1];
        v2.erase(v2.begin()+i+1);
        op2.erase(op2.begin()+i);
        --right;
    }
    FOR(i,left,right-1) {
        if (op2[i] == '+') v2[i] += v2[i+1];
        if (op2[i] == '-') v2[i] -= v2[i+1];
        v2.erase(v2.begin()+i+1);
        op2.erase(op2.begin()+i);
        --right; --i;
    }
    right = LAST(v2);
    FOR(i,0,right-1) if (op2[i] == '*') {
        v2[i] = v2[i] * v2[i+1];
        v2.erase(v2.begin()+i+1);
        op2.erase(op2.begin()+i);
        --right;
    }
    FOR(i,left,right-1) {
        if (op2[i] == '+') v2[i] += v2[i+1];
        if (op2[i] == '-') v2[i] -= v2[i+1];
        v2.erase(v2.begin()+i+1);
        op2.erase(op2.begin()+i);
        --right; --i;
    }
    return v2[0];
}

string bieuthuc(int left, int right) {
    string res = "";
//    string temp = "";
    FOR(i,0,LAST(v)) {
        if (i == left && !(left == 0 && right == LAST(v))) res += '(';
        stringstream ss;
        ss << v[i];
//        db(ss.str());
        res += ss.str();
//        db(res);
        if (i == right && !(left == 0 && right == LAST(v))) res += ')';
        res += op[i];
    }
    return res;
}

bool visit(int u) {
    if (visited[u] == t) return false;
    else visited[u] = t;
    forit(it, dsk[u]) if (!ass[*it] || visit(ass[*it])) {
        ass[*it] = u;
        return true;
    }
    return false;
}

int main() {
//    freopen("exam.inp", "r", stdin);
//    freopen("exam.out", "w", stdout);
    scanf("%d\n", &n);
    int cnt = 0;
    FOR(i,1,n) {
        char ch = '@'; LL x;
        v.clear(); op.clear();
        while (ch != '\n') {
            scanf("%lld", &x); v.pb(x);
            scanf("%c", &ch); op.pb(ch);
        }
//        FOR(i,0,LAST(op)-1) if (op[i] == '*') {
//            LL temp = v[i] * v[i+1];
//            v[i] = v[i+1] = temp;
//        }
        FOR(j,0,LAST(v)-1) FOR(k,j+1, LAST(v)) {
            LL val = cal(j,k); int &temp = index[val];
            if (temp == 0) {
                temp = ++cnt;
//                ev[cnt] = val;
                dsk[i].pb(cnt);
                ans[i][cnt] = bieuthuc(j,k);
//                db(ans[i][cnt]);
            } else {
                dsk[i].pb(temp);
                ans[i][temp] = bieuthuc(j,k);
            }
        }
    }
    t = 0;
    FOR(i,1,n) {
        ++t;
        int temp = visit(i);
        if (!temp) {
            puts("NO SOLUTION");
            return 0;
        }
    }
    FOR(i,1,cnt) if (ass[i]){
        cout << ans[ass[i]][i];
    }
}



