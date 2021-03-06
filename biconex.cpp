# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# include <cstring>
# define NR 100005
# define mod 666013
using namespace std;
ifstream f("biconex.in");
ofstream g("biconex.out");
vector <int> v[NR], sol[NR];
struct elem
{
    int x, y;
}st[NR], E;
int i,j,n,m,x,y,VV,nrsol;
int niv[NR], minn[NR], ap[NR];
void DFS (int k, int nivel, int tata)
{
    ap[k]=1; niv[k]=nivel; minn[k]=nivel;

    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i]!=tata)
        {
            if (! ap[v[k][i]])
            {
                st[++VV].x=k; st[VV].y=v[k][i];
                DFS (v[k][i], nivel+1, k);

                if (minn[v[k][i]]>=nivel)
                {
                    ++nrsol;
                    sol[nrsol].push_back(k);
                    while (st[VV].x!=k)
                    {
                        sol[nrsol].push_back(st[VV].y);
                        --VV;
                    }
                    sol[nrsol].push_back(st[VV].y);
                    --VV;
                }
                minn[k]=min(minn[k], minn[v[k][i]]);
            }
            else minn[k]=min(minn[k], niv[v[k][i]]);
        }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS (1,1,0);

    g<<nrsol<<"\n";
    for (i=1; i<=nrsol; ++i)
    {
        for (j=0; j<sol[i].size(); ++j)
            g<<sol[i][j]<<" ";
        g<<"\n";
    }

    return 0;
}
