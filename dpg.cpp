#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

int v,e,x,y,dp[100010],vis[100010];
vector<int> g[100010],s;

void dfs(int v) 
{
    FOR(i,0,g[v].size())
    {
        if(!vis[g[v][i]])
        {
            vis[g[v][i]]=1;
            dfs(g[v][i]);
            s.push_back(g[v][i]);
        }
    }    
}

int main()
{
    cin>>v>>e;
    FOR(i,0,e) cin>>x>>y,g[x].push_back(y);
    FOR(i,1,v+1) if(!vis[i]) {
        vis[i]=1;
        dfs(i);
        s.push_back(i);
    } 
    for(int i=s.size()-1;i>=0;i--)
    {
        FOR(j,0,g[s[i]].size())
        {
            dp[g[s[i]][j]]=max(dp[g[s[i]][j]],dp[s[i]]+1);
        }
    }
    cout<<*max_element(dp+1,dp+v+1)<<'\n';


    return 0;
}