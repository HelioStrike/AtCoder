#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define N 100010
using namespace std;

ll n,m,x,y,p[N],dp[N],dp2[N],pre[N],suf[N];
vector<int> g[N];

void dfs(int u,int p)
{
    for(int v: g[u])
    {
        if(v==p) continue;
        dfs(v,u);
        dp[u]=(dp[u]*(dp[v]+1))%m;
    }
}

void dpf(int u,int p)
{
    int l=g[u].size(),k=0;
    pre[0]=1;
    FOR(i,0,l)
    {
        int son=g[u][i];
        if(son==p) continue;
        k++;
        pre[k]=(pre[k-1]*(dp[son]+1))%m;
    }
    suf[k+1]=1;
    for(int i=l-1;i>=0;i--)
    {
        int son=g[u][i];
        if(son==p) continue;
        suf[k]=(suf[k+1]*(dp[son]+1))%m;
        k--;
    }
    k=0;
    FOR(i,0,l)
    {
        int son=g[u][i];
        if(son==p) continue;
        k++;
        dp2[son]=((dp2[u]*pre[k-1])%m*suf[k+1]+1)%m;
    }
    FOR(i,0,l)
    {
        int son=g[u][i];
        if(son==p) continue;
        dpf(son,u);
    }
}

int main()
{
    cin>>n>>m;
    FOR(i,0,N) dp[i]=dp2[i]=1;
    FOR(i,1,n)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,-1);
    dpf(1,-1);
    FOR(i,1,n+1) cout<<(dp[i]*dp2[i])%m<<'\n';

    return 0;
}