#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define M 1000000007
#define N 100010
using namespace std;

int n,x,y;
vector<int> g[N];
ll dp[N][2];

void dfs(int u,int p)
{
    dp[u][0]=dp[u][1]=1;
    for(int v: g[u])
    {
        if(v!=p)
        {
            dfs(v,u);
            dp[u][0]=(dp[u][0]*dp[v][1])%M;
            dp[u][1]=((dp[v][0]+dp[v][1])*dp[u][1])%M;
        }
    }
}

int main()
{
    cin>>n; FOR(i,1,n) cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
    dfs(1,0);
    cout<<(dp[1][0]+dp[1][1])%M<<'\n';

    return 0;
}