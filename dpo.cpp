#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define M 1000000007
#define N 22
using namespace std;

ll n,k,a[N][N],dp[N][1<<N];
vector<int> states[N];

int main()
{
    cin>>n; FOR(i,1,n+1) FOR(j,1,n+1) cin>>a[i][j];
    for(int j=2;j<(1<<(n+1));j+=2) states[__builtin_popcount(j)].push_back(j);
    dp[0][0]=1;
    FOR(i,1,n+1)
    {
        for(int j: states[i])
        {
            FOR(k,1,n+1)
            {
                if(!(j&(1<<k)) || a[i][k]==0) continue;
                dp[i][j]=(dp[i][j]+dp[i-1][j^(1<<k)])%M;
            }
        }
    }
    cout<<dp[n][(1<<(n+1))-2]<<'\n';

    return 0;
}