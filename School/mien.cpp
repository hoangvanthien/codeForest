#include <bits/stdc++.h>

using namespace std;

#define MaxN 101

int ar[MaxN][MaxN];
bool tt[MaxN][MaxN];
int Max,Count,m,n,_count;

void init()
{
	FILE *pfile;
	pfile = fopen("mien.inp","r");
	fscanf(pfile, "%d%d", &m, &n);
	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
		{
			int x;
			fscanf(pfile,"%d",&x);
			ar[i][j] = x;
			if (x==1) tt[i][j]=true;
			else tt[i][j] = false;
		}
	Max = 0;
	Count = 0;
}

void print()
{
    FILE *pfile;
    pfile = fopen("mien.out", "w");
    fprintf(pfile, "%d\n%d", Count, Max);
}

void loang(int i, int j)
{
    if (!(0<=i && i<m && 0<=j && j<n)) return;
    if (tt[i][j] == true) return;
    _count++;
    tt[i][j] = true;
    loang(i+1,j);
    loang(i,j+1);
    loang(i-1,j);
    loang(i,j-1);
}

int main()
{
    init();
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
        if (tt[i][j] == false)
    {
        Count++;
        _count = 0;
        loang(i,j);
        if (_count>Max) Max = _count;
        /*for (int ii=0; ii<m; ++ii)
        {
            for (int jj=0; jj<n; ++jj)
                printf("%d ", (int)tt[ii][jj]);
            printf("\n");
        }
        cin.ignore();*/
    }
    print();
}
