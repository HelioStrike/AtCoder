#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 310
using namespace std;

int n,x,a[4];
double dp[N][N][N];

int main()
{
    cin>>n; FOR(i,0,n) cin>>x,a[x]++;
    FOR(k,0,n+1)
    {
        FOR(j,0,n+1)
        {
            FOR(i,0,n+1)
            {
                if(i+j+k==0 || i+j+k>n) continue;
                dp[i][j][k]=1;
                if(i) dp[i][j][k]+=i*dp[i-1][j][k]/n;
                if(j) dp[i][j][k]+=j*dp[i+1][j-1][k]/n;
                if(k) dp[i][j][k]+=k*dp[i][j+1][k-1]/n;
                dp[i][j][k]*=n*1.0f/(i+j+k);
            }
        }
    }
    cout<<setprecision(10)<<dp[a[1]][a[2]][a[3]]<<'\n';

    return 0;
}