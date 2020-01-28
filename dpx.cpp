#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define N 1010
#define M 10000010
using namespace std;

struct block{ ll w,s,v; };

int n;
ll ans,dp[M];
block bs[N];

bool cmp(block a, block b) { return (a.w+a.s<b.w+b.s); }

int main()
{
    cin>>n; FOR(i,0,n) cin>>bs[i].w>>bs[i].s>>bs[i].v;
    sort(bs,bs+n,cmp);
    FOR(i,0,n)
    {
        for(int j=bs[i].s;j>=0;j--)
        {
            dp[j+bs[i].w]=max(dp[j+bs[i].w],dp[j]+bs[i].v);
        }
    }
    FOR(i,0,M) ans=max(ans,dp[i]);    
    cout<<ans<<'\n';

    return 0;
}