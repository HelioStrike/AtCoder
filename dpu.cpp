#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define N 17
using namespace std;

ll n,k,a[N][N],cs[1<<N],dp[1<<N];

int main()
{
    cin>>n; FOR(i,0,n) FOR(j,0,n) cin>>a[i][j];
    FOR(s,0,1<<n)
    {
        FOR(i,0,n)
        {
            FOR(j,0,i)
            {
                if(((s>>i)&1) && ((s>>j)&1)) cs[s]+=a[i][j];
            }
        }
    }
    FOR(s,1,1<<n)
    {
        for(int k=s;k;k=(k-1)&s)
        {
            dp[s]=max(dp[s],cs[k]+cs[s^k]);
        }
    }
    cout<<dp[(1<<n)-1]<<'\n';

    return 0;
}