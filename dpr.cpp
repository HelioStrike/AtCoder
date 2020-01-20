#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define M 1000000007
#define N 51
using namespace std;

ll n,k,ans,a[N][N],b[N][N],c[N][N];

void mul(ll m1[N][N],ll m2[N][N],ll t[N][N])
{
    memset(t,0,N*N*sizeof(ll));
    FOR(i,0,n) FOR(j,0,n) FOR(k,0,n) t[i][j]=(t[i][j]+m1[i][k]*m2[k][j])%M;
}

int main()
{
    cin>>n>>k; FOR(i,0,n) FOR(j,0,n) cin>>a[i][j];
    FOR(i,0,N) c[i][i]=1;
    while(k)
    {
        if(k&1) 
        {
            mul(a,c,b);
            FOR(i,0,N) FOR(j,0,N) c[i][j]=b[i][j];
        }
        mul(a,a,b);
        FOR(i,0,N) FOR(j,0,N) a[i][j]=b[i][j];
        k>>=1;
    }
    FOR(i,0,n) FOR(j,0,n) ans=(ans+c[i][j])%M;
    cout<<ans<<'\n';

    return 0;
}