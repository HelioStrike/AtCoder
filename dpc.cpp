#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 100010
using namespace std;

int n,dp[3][3],hp[3];

int main()
{
    cin>>n;
    FOR(i,0,n)
    {
        FOR(j,0,3) cin>>hp[j];
        FOR(j,0,3)
        {
            FOR(k,0,3)
            {
                if(j!=k) dp[(i+1)%3][k]=max(dp[(i+1)%3][k],dp[i%3][j]+hp[k]);
            }
        }
    }
    cout<<max(dp[n%3][0],max(dp[n%3][1],dp[n%3][2]))<<'\n';

    return 0;
}